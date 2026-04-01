# 📚 Library Management System (C++ Console Application)

A console-based **Library Management System** built in C++ using Object-Oriented Programming and STL (`vector`).
This project simulates basic library operations such as adding books, displaying available books, issuing books, and returning them.

---

## 🧠 Project Overview

This system allows users to:

* ➕ Add new books to the library
* 📖 View all books with availability status
* 📥 Issue a book
* 📤 Return a book
* 🚪 Exit the system

The application uses a **menu-driven interface** and manages books dynamically using a vector.

---

## ✨ Features

* 🧩 Multi-class design (`Book` and `Library`)
* 📦 Dynamic storage using `vector`
* 📊 Real-time book availability tracking
* 📥 Issue and return functionality with validation
* 🚫 Handles invalid book IDs
* 🔄 Continuous operation until user exits

---

## 🛠️ Technologies Used

* C++
* Standard Library:

  * `iostream` (input/output)
  * `vector` (dynamic storage)

---

## 📸 Sample Output

```id="fj2w9n"
=== LIBRARY MANAGEMENT SYSTEM ===

1. Add Book
2. Show Books
3. Issue Book
4. Return Book
5. Exit

Enter Your Choice: 1

Enter ID: 101
Enter Title: C++ Programming
Enter Author Name: Bjarne Stroustrup

Book added successfully!
```

---

## 🧠 How It Works

* Each book is represented by a `Book` object
* All books are stored in a `vector` inside the `Library` class
* The system searches books using their ID
* Book availability is tracked using a boolean flag (`isIssued`)

---

## 📚 What I Learned

* Multi-class design in C++
* Object-Oriented Programming concepts
* Using STL (`vector`) for dynamic data handling
* Implementing real-world system logic
* Managing state (book availability)
* Building structured and modular programs

---

## 👨‍💻 Author

Developed by *Muhhammad Nauman* as part of my C++ learning journey.

---
