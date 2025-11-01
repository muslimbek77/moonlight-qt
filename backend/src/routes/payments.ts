import express, { Response } from 'express';
import { storage } from '../../../server/storage';
import { authenticateToken, AuthRequest } from '../middleware/auth';

const router = express.Router();

router.use(authenticateToken);

router.get('/balance', async (req: AuthRequest, res: Response) => {
  try {
    const userId = req.userId!;
    const user = await storage.getUser(userId);
    
    if (!user) {
      return res.status(404).json({ error: 'User not found' });
    }

    res.json({ balance: user.balance });
  } catch (error) {
    console.error('Get balance error:', error);
    res.status(500).json({ error: 'Failed to get balance' });
  }
});

router.post('/deposit', async (req: AuthRequest, res: Response) => {
  try {
    const userId = req.userId!;
    const { amount } = req.body;

    if (!amount || parseFloat(amount) <= 0) {
      return res.status(400).json({ error: 'Invalid amount' });
    }

    const user = await storage.getUser(userId);
    if (!user) {
      return res.status(404).json({ error: 'User not found' });
    }

    const transaction = await storage.createTransaction({
      userId,
      amount: parseFloat(amount).toFixed(2),
      type: 'deposit',
      status: 'completed',
      description: 'Balance deposit',
    });

    const newBalance = (parseFloat(user.balance) + parseFloat(amount)).toFixed(2);
    await storage.updateUserBalance(userId, newBalance);

    res.json({ 
      success: true,
      transaction,
      newBalance,
    });
  } catch (error) {
    console.error('Deposit error:', error);
    res.status(500).json({ error: 'Failed to process deposit' });
  }
});

router.get('/transactions', async (req: AuthRequest, res: Response) => {
  try {
    const userId = req.userId!;
    const transactions = await storage.getUserTransactions(userId);
    res.json({ transactions });
  } catch (error) {
    console.error('Get transactions error:', error);
    res.status(500).json({ error: 'Failed to get transactions' });
  }
});

export default router;
