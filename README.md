# 🏦 Bank System Project 💼

> **A simple console-based application implementing object-oriented programming principles for efficient banking operations.**

---

## 🌟 Project Overview

This **C++ Bank Management System** is developed as part of the *11_OOP as it Should Be (Applications)* course by Mr. Mohammed Abu-Hadhoud. It provides a structured way to manage client and user accounts, track financial transactions, and enforce access control with a permission system. The project utilizes **object-oriented programming (OOP)**, data encryption, and file-based storage for secure and persistent data management.

---

## ✨ Features

### 📋 Object-Oriented Design
- Encapsulation of client and user data.
- Modular project structure with segmented functionality.

### 🔒 Security & Data Management
- **Caesar Cipher Encryption**: Ensures basic security for stored data.
- **File-Based Database**: Uses text files to store client and user records.
- **User Tracking**: Logs login attempts and transaction activities.

### 👥 Client Management
- ➕ **Add New Clients**
- 🗒️ **Update Client Details**
- ❌ **Delete Clients**
- 🔍 **Search for Clients**
- 🗂 **View All Clients**

### 💸 Financial Transactions
- 💰 **Deposit Funds**
- 💳 **Withdraw Money**
- 📊 **View Total Balances**
- 📃 **Transaction Logs**

### 🤝 User Management
- ➕ **Add New Users**
- 🗒️ **Update User Details**
- ❌ **Delete Users**
- 🔍 **Search for Users**
- 🗂 **View All Users**
- 🔐 **Manage User Permissions**

### 🛡️ Permission Management
- **Role-based Access Control**
- Restrict functionalities based on user roles.

---

## 🛠️ Code Structure

### Data Structures
- **stClient**: Stores client information.
- **stUser**: Stores user details.

### Enumerations
- **enMainMenuPermissions**: Defines user roles.
- **enTransactionsMenuOptions**: Controls transaction operations.
- **enManageUsersMenuOptions**: Handles user-related actions.

### Functions
- **CRUD Operations**: Create, Read, Update, and Delete for users and clients.
- **Transaction Handling**: Deposit, withdraw, and log transactions.
- **Data Encryption**: Implements Caesar Cipher for security.
- **File Management**: Reads/writes data from files securely.

---

## 📚 Screens Implemented
- 🌟 Welcome Screen
- 🔐 Login & Logout Screens
- 📋 Main Dashboard
- 📅 Client & User Management Screens
- 📈 Transaction Management Screens
- ⚠️ Permission Error & Failed Login Screens
- 🗃 Transfer Logs & Activity Tracking

---

## 🔧 How It Works

1. **User Authentication**
   - Secure login/logout process.
   - Permission-based access to features.

2. **Client & User Management**
   - Add, edit, delete, and search clients and users.
   
3. **Financial Transactions**
   - Handle deposits, withdrawals, and balance tracking.
   
4. **File Handling**
   - Uses `Clients.txt` and `Users.txt` for persistent data storage.
   
5. **Logging & Security**
   - Tracks all user logins, transfers, and administrative actions.
   
---

## 🎯 Future Improvements
- 🔒 **Advanced Encryption**: Implement stronger security for sensitive data.
- 📅 **Database Integration**: Transition from text files to SQL-based storage.
- 🖥️ **Graphical User Interface (GUI)**: Develop a more interactive UI.
- 🎯 **Enhanced Logging System**: Implement detailed audit logs.

---

## ⚙️ Technologies Used
- **Language**: C++
- **Programming Paradigm**: Object-Oriented Programming (OOP)
- **File Handling**: Text-based persistent storage

---

## 📈 Learning Outcomes
- ✅ **Modular Programming**: Organize code into reusable components.
- ✅ **Data Security**: Implement basic encryption techniques.
- ✅ **File Handling**: Store and retrieve data efficiently.
- ✅ **Transaction Management**: Maintain financial records securely.
- ✅ **Access Control**: Implement user role management.

---

## 📚 License
This project is open-source. Feel free to use and modify it! 🎉

---

## 🤝 Contributions
Contributions are welcome! Submit a pull request with your improvements.

---

## 🏁 Getting Started

### ⚡ How to Run
1. **Clone the Repository** to your local machine.
2. **Compile** the C++ code using your preferred compiler (e.g., `g++`).
3. **Run** the executable and start managing banking operations!

---

