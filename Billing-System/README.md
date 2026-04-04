# 🛒 Billing System (Console-Based in C++)

## 📌 Overview

The **Billing System** is a console-based C++ application that simulates a simple **Point of Sale (POS)** system. It allows users to manage inventory, handle cart operations, and generate a final bill efficiently.

This project demonstrates strong understanding of **Object-Oriented Programming (OOP)** concepts along with practical usage of **STL (vector)** to solve a real-world problem.

---

## 🚀 Features

### 🏪 Inventory Management

* ➕ Add products to inventory
* 🚫 Prevent duplicate product entries
* 📦 Display all available products

### 🛒 Cart Operations

* ➕ Add products to cart
* 🚫 Prevent duplicate items in cart
* 📋 View cart details
* ❌ Remove item from cart (with stock restoration)
* 🔄 Start a new cart (reset)

### 💰 Billing System

* 🧮 Calculate total bill
* 🧾 Print detailed bill with items and total

### ⚙️ System Controls

* ❌ Exit system safely

---

## 🧱 Project Structure

### 🔹 `Product` Class

Represents each product in the inventory:

* ID
* Name
* Stock quantity
* Price

### 🔹 `CartItem` Class

Represents items added to the cart:

* Product name
* Price
* Quantity

### 🔹 `BillingSystem` Class

Core logic handler:

* Inventory management
* Cart handling
* Billing calculations
* Stock updates

---

## 🧠 Concepts Used

* Object-Oriented Programming (Classes & Objects)
* Constructors & Initialization Lists
* STL (`vector`)
* Loops & Conditional Statements
* Input Handling (`cin`, `getline`)
* Algorithm Library (`transform`, `remove_if`)
* Basic System Design

---

## 🔄 Program Flow

1. Add products to inventory
2. Display available products
3. Add products to cart
4. View cart details
5. Remove item (optional)
6. Calculate or print bill
7. Start a new cart or exit

---

## 💡 Sample Menu

```
1. Add product in Stock
2. Display All Products
3. Add to Cart
4. Show Cart
5. Calculate Bill
6. New Cart
7. Delete Item from Cart
8. Print Bill
9. Exit
```

---

## 🎯 Learning Outcomes

* Built a real-world console application using C++
* Applied OOP concepts in a structured way
* Practiced working with dynamic data using vectors
* Implemented inventory & billing logic
* Improved problem-solving and edge-case handling

---

## 🔮 Future Improvements

* 🔍 Search product by ID or name
* 💾 File handling (save/load data)
* 📊 Better bill formatting (receipt-style output)
* 🖥️ GUI version (Qt / Web-based)
* 🧾 Discount & tax system
* 👥 Multi-user support

---

## 👨‍💻 Author

**Muhammad Nauman**

---

## ⭐ GitHub Note

If you found this project useful or interesting, consider giving it a ⭐ on GitHub!

---
