# 🎈 FlyBall C++

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Raylib](https://img.shields.io/badge/raylib-000000?style=for-the-badge&logo=raylib&logoColor=white)
![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)

A 2D arcade-style survival game built with **C++** and the **raylib** graphics library. Control a red ball, fight constant gravity, avoid moving obstacles, and survive as long as you can!

---

## 📸 Screenshots

| Gameplay | Moving Obstacles | Game Over Screen |
| :---: | :---: | :---: |
| <img src="https://i.ibb.co/pvtf8hxB/Screenshot-2026-11-08-103202.png" width="250" alt="Gameplay 1"/> | <img src="https://i.ibb.co/5XDvkCbM/Screenshot-2026-11-08-103213.png" width="250" alt="Gameplay 2"/> | <img src="https://i.ibb.co/pvfJwD8S/Screenshot-2026-11-08-103239.png" width="250" alt="Game Over"/> |

---

## ✨ Features

- **Responsive Controls:** Move multi-directionally (`W`, `A`, `S`, `D`).
- **Dynamic Gravity:** Falling behavior kicks in automatically when directional keys are released.
- **Randomized Obstacles:** Obstacles generate dynamically with semi-random timing.
- **Precise Collision Detection:** Accurate circle-to-rectangle collision checks using Raylib.
- **Game State Management:** Features a clear Game Over screen with immediate restart support (`R`).

---

## 🎮 Controls

| Key | Action |
| :---: | :--- |
| `W` | Move Up / Thrust |
| `S` | Move Down |
| `A` | Move Left |
| `D` | Move Right |
| `R` | Restart Game (on Game Over) |

---

## 🛠️ Tech Stack & Requirements

- **Language:** C++ (`std::cout`, standard library functions)
- **Graphics Library:** [raylib](https://www.raylib.com/)
- **Compiler:** g++ or any standard C++17 compatible compiler

---

## 🚀 Building & Running

### 1. Prerequisites
Ensure you have C++ and `raylib` installed on your machine.
- **Linux (GCC):** `sudo apt install libraylib-dev`
- **macOS (Homebrew):** `brew install raylib`
- **Windows:** Install Raylib via MinGW or Visual Studio.

### 2. Compilation
Compile the source file `main.cpp` using your terminal:

```bash
g++ main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o FlyBall
```

*(Note: Flags may vary slightly depending on your OS and compiler environment).*

### 3. Execution
Run the compiled executable:

```bash
./FlyBall
```

---

## 📜 Code Structure Overview

- **Window Setup:** 500x500 pixel viewport locked at 60 FPS.
- **Gravity Logic:** Increases `y` coordinate when no key input is detected.
- **Collision:** Evaluated using `CheckCollisionCircleRec(playerPos, radius, obstacleRect)`.

---

## 📄 License

This project is open-source and available under the [MIT License](LICENSE).