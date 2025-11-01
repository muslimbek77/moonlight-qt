import axios, { AxiosInstance } from 'axios';
import * as cheerio from 'cheerio';

const CLOUDPLAY_BASE_URL = 'https://ctrl.cloudplay.uz';

export interface CloudPlaySlot {
  id: string;
  name: string;
  ipAddress: string;
  status: string;
  pinCode?: string;
  isActive: boolean;
}

export class CloudPlayClient {
  private axiosInstance: AxiosInstance;
  private isAuthenticated: boolean = false;
  private sessionCookie: string = '';

  constructor() {
    this.axiosInstance = axios.create({
      baseURL: CLOUDPLAY_BASE_URL,
      timeout: 30000,
      headers: {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36',
        'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
      },
      withCredentials: true,
    });
  }

  async login(username: string, password: string): Promise<boolean> {
    try {
      const loginPageResponse = await this.axiosInstance.get('/login/');
      const $ = cheerio.load(loginPageResponse.data);
      const csrfToken = $('input[name="csrfmiddlewaretoken"]').val() as string;

      const cookies = loginPageResponse.headers['set-cookie'];
      if (cookies) {
        this.sessionCookie = cookies.map(cookie => cookie.split(';')[0]).join('; ');
      }

      const formData = new URLSearchParams();
      formData.append('username', username);
      formData.append('password', password);
      formData.append('csrfmiddlewaretoken', csrfToken);

      const loginResponse = await this.axiosInstance.post('/login/', formData, {
        headers: {
          'Content-Type': 'application/x-www-form-urlencoded',
          'Cookie': this.sessionCookie,
          'Referer': `${CLOUDPLAY_BASE_URL}/login/`,
        },
        maxRedirects: 0,
        validateStatus: (status) => status >= 200 && status < 400,
      });

      const loginCookies = loginResponse.headers['set-cookie'];
      if (loginCookies) {
        this.sessionCookie = loginCookies.map(cookie => cookie.split(';')[0]).join('; ');
      }

      this.isAuthenticated = loginResponse.status === 302 || loginResponse.status === 200;
      return this.isAuthenticated;
    } catch (error) {
      console.error('CloudPlay login error:', error);
      return false;
    }
  }

  async getAvailableSlots(): Promise<CloudPlaySlot[]> {
    if (!this.isAuthenticated) {
      throw new Error('Not authenticated. Please login first.');
    }

    try {
      const response = await this.axiosInstance.get('/ipaddress/', {
        headers: {
          'Cookie': this.sessionCookie,
        },
      });

      const $ = cheerio.load(response.data);
      const slots: CloudPlaySlot[] = [];

      $('.ip-card, .slot-item, tr').each((_, element) => {
        const $el = $(element);
        const id = $el.attr('data-uuid') || $el.attr('data-id') || '';
        const name = $el.find('.ip-name, .slot-name').text().trim();
        const ipAddress = $el.find('.ip-address').text().trim();
        const isActive = $el.find('.status-active').length > 0 || $el.hasClass('active');

        if (id && (name || ipAddress)) {
          slots.push({
            id,
            name: name || `Slot ${id.substring(0, 8)}`,
            ipAddress: ipAddress || 'Unknown',
            status: isActive ? 'active' : 'inactive',
            isActive,
          });
        }
      });

      return slots;
    } catch (error) {
      console.error('CloudPlay get slots error:', error);
      throw new Error('Failed to get available slots');
    }
  }

  async toggleSlot(slotId: string, activate: boolean = true): Promise<boolean> {
    if (!this.isAuthenticated) {
      throw new Error('Not authenticated. Please login first.');
    }

    try {
      const toggleUrl = `/ipaddress/${slotId}/toggle-active/`;
      
      const pageResponse = await this.axiosInstance.get(toggleUrl, {
        headers: {
          'Cookie': this.sessionCookie,
        },
      });

      const $ = cheerio.load(pageResponse.data);
      const csrfToken = $('input[name="csrfmiddlewaretoken"]').val() as string;

      const response = await this.axiosInstance.post(toggleUrl, '', {
        headers: {
          'Cookie': this.sessionCookie,
          'X-CSRFToken': csrfToken,
          'Referer': `${CLOUDPLAY_BASE_URL}${toggleUrl}`,
        },
        maxRedirects: 0,
        validateStatus: (status) => status >= 200 && status < 400,
      });

      return response.status === 302 || response.status === 200;
    } catch (error) {
      console.error('CloudPlay toggle slot error:', error);
      return false;
    }
  }

  async getPinCode(slotId: string): Promise<string | null> {
    if (!this.isAuthenticated) {
      throw new Error('Not authenticated. Please login first.');
    }

    try {
      const response = await this.axiosInstance.get(`/ipaddress/${slotId}/`, {
        headers: {
          'Cookie': this.sessionCookie,
        },
      });

      const $ = cheerio.load(response.data);
      const pinCode = $('.pin-code, .code, input[name="pin"]').val() as string || 
                      $('.pin-code, .code').text().trim();

      return pinCode || null;
    } catch (error) {
      console.error('CloudPlay get PIN error:', error);
      return null;
    }
  }

  async submitPinCode(slotId: string, pinCode: string): Promise<boolean> {
    if (!this.isAuthenticated) {
      throw new Error('Not authenticated. Please login first.');
    }

    try {
      const submitUrl = `/ipaddress/${slotId}/`;
      
      const pageResponse = await this.axiosInstance.get(submitUrl, {
        headers: {
          'Cookie': this.sessionCookie,
        },
      });

      const $ = cheerio.load(pageResponse.data);
      const csrfToken = $('input[name="csrfmiddlewaretoken"]').val() as string;

      const formData = new URLSearchParams();
      formData.append('pin_code', pinCode);
      formData.append('csrfmiddlewaretoken', csrfToken);

      const response = await this.axiosInstance.post(submitUrl, formData, {
        headers: {
          'Cookie': this.sessionCookie,
          'Content-Type': 'application/x-www-form-urlencoded',
          'X-CSRFToken': csrfToken,
          'Referer': `${CLOUDPLAY_BASE_URL}${submitUrl}`,
        },
      });

      return response.status === 200 || response.status === 302;
    } catch (error) {
      console.error('CloudPlay submit PIN error:', error);
      return false;
    }
  }

  async createAndEnableMoonlightSlot(username?: string, password?: string): Promise<CloudPlaySlot | null> {
    try {
      if (!this.isAuthenticated) {
        const cloudplayUsername = username || process.env.CLOUDPLAY_USERNAME;
        const cloudplayPassword = password || process.env.CLOUDPLAY_PASSWORD;

        if (!cloudplayUsername || !cloudplayPassword) {
          throw new Error('CloudPlay credentials not provided');
        }

        const loginSuccess = await this.login(cloudplayUsername, cloudplayPassword);
        
        if (!loginSuccess) {
          throw new Error('Failed to authenticate with CloudPlay');
        }
      }

      const availableSlots = await this.getAvailableSlots();
      
      let targetSlot = availableSlots.find(slot => !slot.isActive);
      
      if (!targetSlot && availableSlots.length > 0) {
        targetSlot = availableSlots[0];
      }

      if (!targetSlot) {
        throw new Error('No slots available');
      }

      if (!targetSlot.isActive) {
        const activated = await this.toggleSlot(targetSlot.id, true);
        if (!activated) {
          throw new Error('Failed to activate slot');
        }
        targetSlot.isActive = true;
        targetSlot.status = 'active';
      }

      const pinCode = await this.getPinCode(targetSlot.id);
      if (pinCode) {
        targetSlot.pinCode = pinCode;
      }

      return targetSlot;
    } catch (error) {
      console.error('CloudPlay create Moonlight slot error:', error);
      return null;
    }
  }
}

export const cloudPlayClient = new CloudPlayClient();
