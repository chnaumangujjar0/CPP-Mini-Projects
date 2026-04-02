# 💳 ATM Machine Simulation (C++)

A console-based **ATM Machine Simulation** built in C++ using Object-Oriented Programming principles.
This project demonstrates the evolution from a **single-user system (Version 1)** to a **multi-user system (Version 2)** with authentication and account management.

---

## 🚀 Features

### 🔹 Version 1 (Basic ATM)

* Single user system
* PIN-based login
* Deposit money
* Withdraw money
* Check balance
* Change PIN
* Logout functionality

---

### 🔹 Version 2 (Advanced ATM System)

* Multi-user system using `vector`
* Account creation (Sign Up)
* Login using:

  * Account Number
  * PIN authentication
* Session handling using pointers (`currentUser`)
* Deposit & Withdraw operations per user
* Balance checking
* PIN change with validation
* Login attempt limit (security feature)

---

## 🧠 Concepts Used

* Object-Oriented Programming (OOP)

  * Classes & Objects
  * Encapsulation
* Constructors
* Pointers (`ATM* currentUser`)
* Vectors (`vector<ATM>`)
* Control Flow (loops, conditionals)
* Input validation
* Basic system design

---

## 🏗️ Project Structure

```
ATM System
│
├── ATM Class
│   ├── Account details (name, pin, balance, accountNumber)
│   ├── depositBalance()
│   ├── withdrawBalance()
│   ├── displayBalance()
│   ├── changePin()
│   └── checkLogin()
│
├── UserSystem Class
│   ├── vector<ATM> users
│   ├── createAccount()
│   └── login()
│
└── Main Function
    ├── Login / Signup Loop
    ├── Menu System
    └── Session Handling
```

---

## 🔐 Authentication Flow

1. User enters:

   * Account Number
   * PIN
2. System searches user in `vector`
3. If matched:

   * Login successful
   * Pointer (`currentUser`) assigned
4. All operations performed on logged-in user

---

## 💡 Key Learning Outcomes

* Transition from **single-object system → multi-user system**
* Understanding **pointer-based object access**
* Designing **real-world console applications**
* Managing **state and user sessions**
* Writing **modular and scalable code**

---

## 📌 Future Improvements

* File handling (save accounts permanently)
* Password masking
* Transaction history
* GUI version
* Admin panel

---

## ⭐ Author

**Nauman**
C++ Developer (Learning Journey 🚀)

---

## 📣 Note

This project is part of a structured C++ learning journey progressing from:

> Basics → OOP → Mini Projects → Real-world Systems

---

