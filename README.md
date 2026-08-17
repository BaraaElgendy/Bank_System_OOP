# 🏦 Bank Management System — C++ OOP

A console-based banking system built in **C++** using **Object-Oriented Programming** principles. Simulates core banking operations — client accounts, transactions, user permissions, and persistent data storage — through a clean, layered class architecture.

---

## 📋 Overview

This project models a real-world banking workflow end-to-end: employees log in with role-based permissions, manage client accounts, process deposits/withdrawals/transfers, and every action is persisted to disk. It was built as a deep dive into applying OOP principles to a multi-screen, multi-entity system rather than an isolated exercise.

The system is organized into two major modules built on a shared architecture — demonstrating how a well-designed OOP foundation (base screen classes, shared persistence logic, reusable validation) lets new functionality be added without rebuilding the system from scratch.

---

## ✨ Features

### 🏦 Module 1 — Bank System

**Client Management**
- Add, update, delete, and search client records
- List all clients with real-time balance totals

**Transactions**
- Deposit and withdraw funds
- Transfer between accounts with logged transfer history
- Running balance calculations across all accounts

**User & Access Control**
- Login / logout system
- Bitwise permission flags for granular access control per user
- Account lockout after repeated failed login attempts
- All login attempts recorded to a log file

**Data Persistence**
- Custom file-based storage (no external database) using serialized `.txt` records
- **Encrypted password storage**
- Full CRUD operations backed by file I/O

### 💱 Module 2 — Currency Exchange

- Add, update, find, and list supported currencies
- Live exchange rate updates
- Built-in currency calculator screen
- Reuses the same screen architecture, file persistence layer, and validation logic as the Bank module

---

## 🏗️ Architecture & OOP Concepts

| Concept | Application |
|---|---|
| **Encapsulation** | Private data members exposed only through controlled public interfaces |
| **Inheritance** | Shared base classes (`clsPerson`, `clsScreen`) eliminate duplication across entities and UI screens |
| **Abstraction** | Complex file I/O and validation logic hidden behind simple method calls |
| **Static Members** | Utility and validation classes (`clsUtil`, `clsInputValidate`) operate without needing object instantiation |
| **Layered Separation** | UI screens are fully decoupled from data/business logic classes |
| **Serialization** | Custom object-to-line and line-to-object conversion for file-based persistence |

---

## 📁 Project Structure

```
├── clsPerson.h              # Base class for shared identity fields
├── clsBankClient.h          # Client entity + banking operations
├── clsUser.h                # System users + authentication
├── clsEmployee.h            # Employee-specific logic
├── clsDate.h                # Date handling utility
├── clsUtil.h                # General-purpose static helpers
├── clsInputValidate.h       # Input validation layer
├── clsString.h               # String manipulation helpers
├── clsCurrency.h              # Currency entity + exchange logic
├── clsScreen.h               # Base UI screen class
├── cls*Screen.h              # Individual UI screens (Login, Deposit, Transfer, Currency, etc.)
├── cls*Menu.h                 # Menu navigation classes
├── Clients.txt / Users.txt   # Persisted data files
├── TransferLog.txt           # Transaction audit log
└── Bank_System_OOP.cpp       # Entry point
```

---

## 🛠️ Tech Stack

- **Language:** C++
- **IDE:** Microsoft Visual Studio
- **Version Control:** Git & GitHub

---

## 🚀 Getting Started

```bash
git clone https://github.com/BaraaElgendy/Bank_System_OOP.git
```

Open `Bank_System_OOP.slnx` in Visual Studio and build/run the solution.

---

## 📌 Status

Actively developed as part of an ongoing OOP learning path — new modules and refinements are added as features are completed.
