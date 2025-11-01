import { users, transactions, gamingSlots } from './schema';
import type { User, InsertUser, Transaction, InsertTransaction, GamingSlot, InsertGamingSlot } from './schema';
import { db } from './db';
import { eq } from 'drizzle-orm';

export interface IStorage {
  getUser(id: number): Promise<User | undefined>;
  getUserByEmail(email: string): Promise<User | undefined>;
  createUser(insertUser: InsertUser): Promise<User>;
  updateUserBalance(userId: number, newBalance: string): Promise<void>;
  updateUser(userId: number, updates: Partial<User>): Promise<void>;
  
  createTransaction(transaction: InsertTransaction): Promise<Transaction>;
  getUserTransactions(userId: number): Promise<Transaction[]>;
  
  createGamingSlot(slot: InsertGamingSlot): Promise<GamingSlot>;
  getUserGamingSlots(userId: number): Promise<GamingSlot[]>;
  updateGamingSlot(slotId: number, updates: Partial<GamingSlot>): Promise<void>;
}

export class DatabaseStorage implements IStorage {
  async getUser(id: number): Promise<User | undefined> {
    const [user] = await db.select().from(users).where(eq(users.id, id));
    return user || undefined;
  }

  async getUserByEmail(email: string): Promise<User | undefined> {
    const [user] = await db.select().from(users).where(eq(users.email, email));
    return user || undefined;
  }

  async createUser(insertUser: InsertUser): Promise<User> {
    const [user] = await db
      .insert(users)
      .values(insertUser)
      .returning();
    return user;
  }

  async updateUserBalance(userId: number, newBalance: string): Promise<void> {
    await db
      .update(users)
      .set({ balance: newBalance, updatedAt: new Date() })
      .where(eq(users.id, userId));
  }

  async updateUser(userId: number, updates: Partial<User>): Promise<void> {
    await db
      .update(users)
      .set({ ...updates, updatedAt: new Date() })
      .where(eq(users.id, userId));
  }

  async createTransaction(transaction: InsertTransaction): Promise<Transaction> {
    const [newTransaction] = await db
      .insert(transactions)
      .values(transaction)
      .returning();
    return newTransaction;
  }

  async getUserTransactions(userId: number): Promise<Transaction[]> {
    return await db
      .select()
      .from(transactions)
      .where(eq(transactions.userId, userId));
  }

  async createGamingSlot(slot: InsertGamingSlot): Promise<GamingSlot> {
    const [newSlot] = await db
      .insert(gamingSlots)
      .values(slot)
      .returning();
    return newSlot;
  }

  async getUserGamingSlots(userId: number): Promise<GamingSlot[]> {
    return await db
      .select()
      .from(gamingSlots)
      .where(eq(gamingSlots.userId, userId));
  }

  async updateGamingSlot(slotId: number, updates: Partial<GamingSlot>): Promise<void> {
    await db
      .update(gamingSlots)
      .set(updates)
      .where(eq(gamingSlots.id, slotId));
  }
}

export const storage = new DatabaseStorage();
