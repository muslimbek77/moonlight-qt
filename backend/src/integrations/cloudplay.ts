import axios from 'axios';

const CLOUDPLAY_API_URL = 'https://ctrl.cloudplay.uz/api';

export interface CloudPlaySlot {
  id: string;
  name: string;
  status: string;
  pinCode?: string;
  gameUrl?: string;
}

export class CloudPlayClient {
  private apiKey: string;

  constructor(apiKey?: string) {
    this.apiKey = apiKey || process.env.CLOUDPLAY_API_KEY || '';
  }

  async createSlot(userId: number, slotName: string): Promise<CloudPlaySlot> {
    try {
      const response = await axios.post(`${CLOUDPLAY_API_URL}/slots/create`, {
        userId,
        slotName,
      }, {
        headers: {
          'Authorization': `Bearer ${this.apiKey}`,
          'Content-Type': 'application/json',
        },
      });
      
      return response.data;
    } catch (error) {
      console.error('CloudPlay API error:', error);
      throw new Error('Failed to create gaming slot');
    }
  }

  async getSlotStatus(slotId: string): Promise<CloudPlaySlot> {
    try {
      const response = await axios.get(`${CLOUDPLAY_API_URL}/slots/${slotId}/status`, {
        headers: {
          'Authorization': `Bearer ${this.apiKey}`,
        },
      });
      
      return response.data;
    } catch (error) {
      console.error('CloudPlay API error:', error);
      throw new Error('Failed to get slot status');
    }
  }

  async startGame(slotId: string, pinCode: string): Promise<{ gameUrl: string }> {
    try {
      const response = await axios.post(`${CLOUDPLAY_API_URL}/slots/${slotId}/start`, {
        pinCode,
      }, {
        headers: {
          'Authorization': `Bearer ${this.apiKey}`,
          'Content-Type': 'application/json',
        },
      });
      
      return response.data;
    } catch (error) {
      console.error('CloudPlay API error:', error);
      throw new Error('Failed to start game');
    }
  }

  async enterPinCode(slotId: string, pinCode: string): Promise<boolean> {
    try {
      const response = await axios.post(`${CLOUDPLAY_API_URL}/slots/${slotId}/pin`, {
        pinCode,
      }, {
        headers: {
          'Authorization': `Bearer ${this.apiKey}`,
          'Content-Type': 'application/json',
        },
      });
      
      return response.data.success;
    } catch (error) {
      console.error('CloudPlay API error:', error);
      return false;
    }
  }

  async checkBalance(userId: number): Promise<number> {
    try {
      const response = await axios.get(`${CLOUDPLAY_API_URL}/users/${userId}/balance`, {
        headers: {
          'Authorization': `Bearer ${this.apiKey}`,
        },
      });
      
      return response.data.balance;
    } catch (error) {
      console.error('CloudPlay API error:', error);
      throw new Error('Failed to check balance');
    }
  }
}

export const cloudPlayClient = new CloudPlayClient();
