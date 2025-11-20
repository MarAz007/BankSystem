# Bank Management System

Description:  
A C++ Bank Management System with Admin and Customer modules.  
Allows secure login, account management, deposits, withdrawals, transfers, and transaction history.  
Demonstrates Object-Oriented Programming (OOP), file handling, and input validation.

---

## Features

### Customer Features
- Create a new account with username, password, and currency type ($ or EGP)
- Login with up to 3 attempts
- Deposit and Withdraw money
- Transfer money to another account
- Check account details (balance, account number, currency)
- Update account information (username, password, currency)
- View transaction history
- Delete account

### Admin Features
- Admin login
- View all accounts
- View all transactions
- Delete any account
- Search for an account by account number
---
## How to Run

1. Open the project in VS Code, Code::Blocks, or any C++ IDE.
2. Compile all .cpp files.
3. Run the executable.
4. Follow the on-screen menu:
   - Choose Admin or Customer
   - Follow prompts to login or create account
   - Perform transactions or manage accounts

---

## Notes
- Currency supported: $ and EGP  
- Account numbers are auto-generated starting from 1000  
- Maximum 3 login attempts for security  
- Transactions are saved in transaction.txt  
- Accounts are saved in account.txt  

---

## Future Improvements
- Password hashing for security
- Lock account after multiple failed attempts
- GUI interface for easier use
- Multi-currency support with exchange rates

---

## Author
Mariam Abdelaziz  
C++ Developer | Bank System Project

