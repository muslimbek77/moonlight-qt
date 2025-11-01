# CloudPlay.uz Web Integration

## Overview
Custom web application that integrates with cloudplay.uz cloud gaming service. Provides user authentication, payment processing, gaming slot management, and automatic game launching.

## Project Goal
Create a full-featured web dashboard that allows users to:
- Register and login to their account
- Manage their balance and make payments
- Add and manage gaming slots
- Automatically launch games through cloudplay.uz service
- Enter PIN codes for game access
- Check balance before starting games

## Tech Stack
- **Frontend**: React + TypeScript + Vite
- **UI**: Tailwind CSS
- **Backend**: Node.js + Express + TypeScript
- **Database**: PostgreSQL (Replit/Neon)
- **ORM**: Prisma
- **Authentication**: JWT tokens
- **Payments**: Stripe integration
- **External API**: cloudplay.uz API (https://ctrl.cloudplay.uz/api)

## Project Structure
```
/
├── frontend/          # React + Vite application
│   ├── src/
│   │   ├── components/    # React components
│   │   ├── pages/         # Page components
│   │   ├── services/      # API client services
│   │   ├── hooks/         # Custom React hooks
│   │   └── types/         # TypeScript types
│   └── package.json
│
├── backend/           # Express API server
│   ├── src/
│   │   ├── routes/        # API routes
│   │   ├── controllers/   # Request handlers
│   │   ├── services/      # Business logic
│   │   ├── models/        # Database models
│   │   ├── middleware/    # Auth, validation, etc.
│   │   └── integrations/  # CloudPlay API client
│   └── package.json
│
└── prisma/            # Database schema and migrations
```

## Key Features
1. **User Management**
   - Registration with email/password
   - Login with JWT token authentication
   - User profile management

2. **Payment Processing**
   - Stripe integration for balance top-up
   - Transaction history
   - Balance tracking

3. **Gaming Slot Management**
   - Add new gaming slots via cloudplay.uz
   - View active slots
   - Manage slot configurations

4. **Automatic Game Launching**
   - Check user balance before launching
   - Communicate with cloudplay.uz API
   - Handle PIN code entry
   - Auto-start games when balance is sufficient

5. **CloudPlay Integration**
   - API wrapper for cloudplay.uz endpoints
   - Slot creation and management
   - PIN code handling
   - Session management

## API Integration
The application uses cloudplay.uz API (https://ctrl.cloudplay.uz/api) for:
- Creating and managing gaming slots
- Getting PIN codes for game access
- Checking slot status
- Managing gaming sessions

## Recent Changes
- 2024-11-01: Project initialized, removed Moonlight Qt code, starting fresh web application

## User Preferences
- Language: Uzbek (Latin)
- Target users: Uzbekistan gaming community
