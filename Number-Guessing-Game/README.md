# 🎯 Number Guessing Game (C++)

A simple and interactive **console-based number guessing game** written in C++.
The program generates a random number, and the player has to guess it within a limited number of attempts.

---

## 🧠 How It Works

* The computer generates a random number between **1 and 100**
* The player enters guesses
* The program gives feedback:

  * 📈 Too high
  * 📉 Too low
  * 🔥 Very close (if difference is small)
* The game continues until:

  * ✅ The player guesses correctly
  * ❌ The player runs out of attempts

---

## ✨ Features

* 🎲 Random number generation
* 🔁 Multiple attempts with limit
* 💡 Hint system (Very close / Close)
* 🚫 Input validation (range checking)
* 🔄 Play again option
* 📊 Attempt counter

---

## 🛠️ Technologies Used

* C++
* Standard Library (`iostream`, `cstdlib`, `ctime`)

---

## ▶️ How to Run

### 🔧 Compile:

```bash
g++ main.cpp -o game
```

### ▶️ Run:

```bash
./game
```

---

## 📸 Sample Output

```
=== Guess Number (1 to 100) ===

Enter your guess: 50
Too low!
🙂 Close!
9 attempts left

Enter your guess: 75
Too high!
🔥 Very close!
8 attempts left

Enter your guess: 70
🎉 Congratulations! You guessed it in 3 attempts.
```

---

## 📚 What I Learned

* Loops and conditional logic
* Random number generation
* Input validation
* Function design in C++
* Writing clean and structured programs

---

## 🚀 Future Improvements

* Difficulty levels (Easy / Medium / Hard)
* Score tracking system
* Better UI (colors or formatting)
* Timer-based challenge

---

## 👨‍💻 Author

Developed by *Muhammad Nauman* as part of C++ learning journey.

---
