import express, { Response } from 'express';
import { storage } from '../db/storage';
import { cloudPlayClient } from '../integrations/cloudplay';
import { authenticateToken, AuthRequest } from '../middleware/auth';

const router = express.Router();

router.use(authenticateToken);

router.get('/', async (req: AuthRequest, res: Response) => {
  try {
    const userId = req.userId!;
    const slots = await storage.getUserGamingSlots(userId);
    res.json({ slots });
  } catch (error) {
    console.error('Get slots error:', error);
    res.status(500).json({ error: 'Failed to get gaming slots' });
  }
});

router.post('/enable-moonlight', async (req: AuthRequest, res: Response) => {
  try {
    const userId = req.userId!;
    const { username, password } = req.body;

    if (!username || !password) {
      return res.status(400).json({ error: 'CloudPlay username and password required' });
    }

    const cloudPlaySlot = await cloudPlayClient.createAndEnableMoonlightSlot(username, password);
    if (!cloudPlaySlot) {
      return res.status(500).json({ error: 'Failed to enable Moonlight slot' });
    }

    const slot = await storage.createGamingSlot({
      userId,
      slotName: cloudPlaySlot.name,
      cloudplaySlotId: cloudPlaySlot.id,
      ipAddress: cloudPlaySlot.ipAddress,
      status: cloudPlaySlot.status,
      pinCode: cloudPlaySlot.pinCode,
    });

    await storage.updateUser(userId, {
      cloudplayUserId: username,
    });

    res.json({ 
      success: true,
      slot: {
        id: slot.id,
        name: slot.slotName,
        ipAddress: cloudPlaySlot.ipAddress,
        pinCode: cloudPlaySlot.pinCode,
        status: cloudPlaySlot.status,
      },
      message: cloudPlaySlot.pinCode 
        ? `Moonlight slot enabled! PIN code: ${cloudPlaySlot.pinCode}` 
        : 'Moonlight slot enabled!'
    });
  } catch (error) {
    console.error('Enable Moonlight error:', error);
    res.status(500).json({ error: 'Failed to enable Moonlight slot' });
  }
});

router.get('/cloudplay-slots', async (req: AuthRequest, res: Response) => {
  try {
    const userId = req.userId!;
    const user = await storage.getUser(userId);

    if (!user || !user.cloudplayUserId) {
      return res.status(400).json({ error: 'CloudPlay credentials not set' });
    }

    const availableSlots = await cloudPlayClient.getAvailableSlots();
    res.json({ slots: availableSlots });
  } catch (error) {
    console.error('Get CloudPlay slots error:', error);
    res.status(500).json({ error: 'Failed to get CloudPlay slots' });
  }
});

router.post('/:slotId/submit-pin', async (req: AuthRequest, res: Response) => {
  try {
    const { slotId } = req.params;
    const { pinCode, cloudplaySlotId } = req.body;

    if (!pinCode) {
      return res.status(400).json({ error: 'PIN code is required' });
    }

    const targetSlotId = cloudplaySlotId || slotId;

    const success = await cloudPlayClient.submitPinCode(targetSlotId, pinCode);
    if (!success) {
      return res.status(400).json({ error: 'Failed to submit PIN code' });
    }

    const slotIdNum = parseInt(slotId);
    if (!isNaN(slotIdNum)) {
      await storage.updateGamingSlot(slotIdNum, {
        status: 'running',
        lastUsedAt: new Date(),
      });
    }

    res.json({ 
      success: true,
      message: 'PIN code submitted successfully. Moonlight should now be accessible.'
    });
  } catch (error) {
    console.error('Submit PIN error:', error);
    res.status(500).json({ error: 'Failed to submit PIN code' });
  }
});

export default router;
