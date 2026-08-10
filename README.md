[README.md.txt](https://github.com/user-attachments/files/30917060/README.md.txt)
# 🏦 OOP Bank Management System (C++)

A comprehensive Console-Based Bank Management System built in **C++** using **Object-Oriented Programming (OOP)** principles. This project simulates real-world banking operations, including client management, transaction handling, user permissions, and data persistence via File I/O.

---

## 🌟 Key Features

*   **👤 Client Management:**
    *   Show Client List
    *   Add New Client
    *   Delete Client
    *   Update Client Info
    *   Find Client
*   **💳 Transactions Menu:**
    *   Deposit Amount
    *   Withdraw Amount
    *   Total Balances List
*   **🔐 User & Permission Management:**
    *   Manage System Users
    *   Custom User Access Permissions (Bitwise Flags)
    *   Login / Logout System
*   **📁 Data Persistence:**
    *   Saves and loads all client & user data from `.txt` files.

---

## 🛠️ Software Architecture & OOP Concepts Applied

This project was built focusing on writing clean, scalable, and modular code:

*   **Encapsulation & Abstraction:** Hiding internal data structures and exposing clean interfaces via Public/Private class members.
*   **Inheritance:** Used Base classes (e.g., `clsPerson`, `clsScreen`) to reduce code redundancy across UI screens and domain objects.
*   **File I/O Stream Handling:** Custom file parsing and serialization/deserialization for saving objects.
*   **Input Validation Utilities:** Robust validation classes (`clsInputValidate`) to handle user input gracefully without crashes.
*   **Layered Architecture Separation:** Clear decoupling between UI Presentation screens and Data/Logic classes.

---

## 💻 Tech Stack & Tools

*   **Language:** C++
*   **IDE:** Microsoft Visual Studio
*   **Version Control:** Git & GitHub

---

## 🚀 How to Run the Project

1. **Clone the Repository:**
   ```bash
   git clone [https://github.com/BaraaElgendy/Bank-System-CPP.git](https://github.com/BaraaElgendy/Bank-System-CPP.git)
