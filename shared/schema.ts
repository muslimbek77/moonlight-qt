import { pgTable, serial, text, timestamp, integer, decimal, boolean } from 'drizzle-orm/pg-core';
import { relations } from 'drizzle-orm';

export const users = pgTable('users', {
  id: serial('id').primaryKey(),
  email: text('email').notNull().unique(),
  name: text('name').notNull(),
  passwordHash: text('password_hash').notNull(),
  balance: decimal('balance', { precision: 10, scale: 2 }).notNull().default('0.00'),
  cloudplayUserId: text('cloudplay_user_id'),
  createdAt: timestamp('created_at').notNull().defaultNow(),
  updatedAt: timestamp('updated_at').notNull().defaultNow(),
});

export const transactions = pgTable('transactions', {
  id: serial('id').primaryKey(),
  userId: integer('user_id').notNull().references(() => users.id),
  amount: decimal('amount', { precision: 10, scale: 2 }).notNull(),
  type: text('type').notNull(), // 'deposit', 'withdrawal', 'game_charge'
  status: text('status').notNull().default('pending'), // 'pending', 'completed', 'failed'
  stripePaymentId: text('stripe_payment_id'),
  description: text('description'),
  createdAt: timestamp('created_at').notNull().defaultNow(),
});

export const gamingSlots = pgTable('gaming_slots', {
  id: serial('id').primaryKey(),
  userId: integer('user_id').notNull().references(() => users.id),
  slotName: text('slot_name').notNull(),
  cloudplaySlotId: text('cloudplay_slot_id').notNull(),
  status: text('status').notNull().default('inactive'), // 'active', 'inactive', 'running'
  pinCode: text('pin_code'),
  gameUrl: text('game_url'),
  createdAt: timestamp('created_at').notNull().defaultNow(),
  lastUsedAt: timestamp('last_used_at'),
});

export const userRelations = relations(users, ({ many }) => ({
  transactions: many(transactions),
  gamingSlots: many(gamingSlots),
}));

export const transactionRelations = relations(transactions, ({ one }) => ({
  user: one(users, {
    fields: [transactions.userId],
    references: [users.id],
  }),
}));

export const gamingSlotRelations = relations(gamingSlots, ({ one }) => ({
  user: one(users, {
    fields: [gamingSlots.userId],
    references: [users.id],
  }),
}));

export type User = typeof users.$inferSelect;
export type InsertUser = typeof users.$inferInsert;
export type Transaction = typeof transactions.$inferSelect;
export type InsertTransaction = typeof transactions.$inferInsert;
export type GamingSlot = typeof gamingSlots.$inferSelect;
export type InsertGamingSlot = typeof gamingSlots.$inferInsert;
