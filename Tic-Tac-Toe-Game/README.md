# ❌⭕ Tic Tac Toe (C++ Console Game)

A console-based **Tic Tac Toe game** developed in C++ using structured programming and game logic.
This is a 2-player interactive game where players take turns marking spaces on a 3×3 grid until one wins or the game ends in a draw.

---

## 🧠 How It Works

* The game board consists of **9 positions (0–8)**
* Player 1 selects either **X or O**
* Player 2 is automatically assigned the other symbol
* Players take turns entering positions on the board
* The game checks for:

  * ✅ Win condition (rows, columns, diagonals)
  * 🤝 Draw condition (all positions filled without a winner)

---

## ✨ Features

* 🎮 Two-player interactive gameplay
* 🔄 Turn-based system
* 🧠 Win detection using pattern matching
* 🚫 Input validation (prevents invalid or repeated moves)
* 📊 Real-time board display after each move
* 🏁 Automatic game result (Win / Draw)

---

## 🛠️ Technologies Used

* C++
* Standard Library (`iostream`)

---

## 📸 Sample Output

```
======= Tic Tac Toe Game =======

Player 1: X
Player 2: O

-------------
| 0 | 1 | 2 |
-------------
| 3 | 4 | 5 |
-------------
| 6 | 7 | 8 |
-------------

Player X, enter position (0-8): 0
...
Player O, enter position (0-8): 4
...
🎉 Player X wins!
```

---

## 🧠 Game Logic

The game uses a **winning pattern array** to check all possible win conditions:

* Rows → 3 possibilities
* Columns → 3 possibilities
* Diagonals → 2 possibilities

This approach avoids multiple conditional statements and keeps the code clean and scalable.

---

## 📚 What I Learned

* 2D/1D array-based game design
* Game loop and turn management
* Input validation and error handling
* Logic building for win/draw conditions
* Writing structured and maintainable code

---

## 👨‍💻 Author

Developed by *Muhammad Nauman* as part of my C++ learning journey.

---
