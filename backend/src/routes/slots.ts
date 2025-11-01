import express, { Response } from 'express';
import { storage } from '../../../server/storage';
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

router.post('/create', async (req: AuthRequest, res: Response) => {
  try {
    const userId = req.userId!;
    const { slotName } = req.body;

    if (!slotName) {
      return res.status(400).json({ error: 'Slot name is required' });
    }

    const cloudPlaySlot = await cloudPlayClient.createSlot(userId, slotName);

    const slot = await storage.createGamingSlot({
      userId,
      slotName,
      cloudplaySlotId: cloudPlaySlot.id,
      status: cloudPlaySlot.status,
      pinCode: cloudPlaySlot.pinCode,
      gameUrl: cloudPlaySlot.gameUrl,
    });

    res.json({ slot });
  } catch (error) {
    console.error('Create slot error:', error);
    res.status(500).json({ error: 'Failed to create gaming slot' });
  }
});

router.post('/:slotId/start', async (req: AuthRequest, res: Response) => {
  try {
    const userId = req.userId!;
    const { slotId } = req.params;
    const { pinCode } = req.body;

    const user = await storage.getUser(userId);
    if (!user) {
      return res.status(404).json({ error: 'User not found' });
    }

    const requiredBalance = 5.0;
    if (parseFloat(user.balance) < requiredBalance) {
      return res.status(400).json({ 
        error: 'Insufficient balance',
        balance: user.balance,
        required: requiredBalance,
      });
    }

    const result = await cloudPlayClient.startGame(slotId, pinCode);

    await storage.updateGamingSlot(parseInt(slotId), {
      status: 'running',
      gameUrl: result.gameUrl,
      lastUsedAt: new Date(),
    });

    const newBalance = (parseFloat(user.balance) - requiredBalance).toFixed(2);
    await storage.updateUserBalance(userId, newBalance);

    await storage.createTransaction({
      userId,
      amount: requiredBalance.toFixed(2),
      type: 'game_charge',
      status: 'completed',
      description: `Game started on slot ${slotId}`,
    });

    res.json({ 
      success: true, 
      gameUrl: result.gameUrl,
      newBalance,
    });
  } catch (error) {
    console.error('Start game error:', error);
    res.status(500).json({ error: 'Failed to start game' });
  }
});

export default router;
