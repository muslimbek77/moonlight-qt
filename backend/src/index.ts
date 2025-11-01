import express, { Request, Response } from 'express';
import cors from 'cors';
import dotenv from 'dotenv';
import authRoutes from './routes/auth';
import slotsRoutes from './routes/slots';
import paymentsRoutes from './routes/payments';

dotenv.config();

const app = express();
const PORT = process.env.PORT || 3000;

app.use(cors());
app.use(express.json());

app.get('/api/health', (req: Request, res: Response) => {
  res.json({ status: 'ok', message: 'CloudPlay Backend API is running' });
});

app.get('/api', (req: Request, res: Response) => {
  res.json({ 
    message: 'CloudPlay.uz Integration API',
    version: '1.0.0',
    endpoints: {
      health: '/api/health',
      auth: '/api/auth/*',
      slots: '/api/slots/*',
      payments: '/api/payments/*'
    }
  });
});

app.use('/api/auth', authRoutes);
app.use('/api/slots', slotsRoutes);
app.use('/api/payments', paymentsRoutes);

app.listen(PORT, () => {
  console.log(`🚀 CloudPlay Backend running on port ${PORT}`);
  console.log(`📡 Health check: http://localhost:${PORT}/api/health`);
  console.log(`📋 Auth: http://localhost:${PORT}/api/auth`);
  console.log(`🎮 Slots: http://localhost:${PORT}/api/slots`);
  console.log(`💰 Payments: http://localhost:${PORT}/api/payments`);
});
