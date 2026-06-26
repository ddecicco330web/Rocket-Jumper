# Rocket-Jumper 2D Game Engine

Rocket-Jumper is a custom, data-driven 2D game engine built from scratch in C++ using the SFML 3 multimedia framework. Developed as a practical exploration of core software engineering principles in game development, the engine focuses on achieving modular subsystem initialization, rigid deterministic simulation updates, and data-driven level generation.

---

## 📝 Table of Contents
1. [Project Description](#-project-description)
2. [Key Features](#-key-features)
3. [Architecture & Patterns Used](#-architecture--patterns-used)
4. [Tech Stack](#-tech-stack)
6. [Future Roadmaps & Implementations](#-future-roadmaps--implementations)
7. [Credits & References](#-credits--references)

---

## 🚀 Project Description 

The motivation behind Rocket-Jumper is to look past commercial "black box" game engines (like Unity or Unreal) and build the low-level foundation entirely from the ground up. This project is specifically architected to handle the distinct challenges of a pixel-perfect 2D platformer. 

Building this engine served as a direct deep-dive into physical memory layout constraints, real-time deterministic updates, and managing hardware abstraction wrappers natively in modern C++.

---

## 🌟 Key Features

- **Deterministic Fixed-Timestep Loop:** Decoupled game simulation updates from the rendering frame rate. Physics calculations run at a hard locked frequency (60Hz) via a clock accumulator, guaranteeing consistent jump heights and collision safety regardless of hardware performance.
- **Data-Driven Level Parsing:** Level maps, layout matrices, metadata, and dynamic enemy spawn locations are kept entirely separate from compiled code, dynamically loaded at runtime using modern structured formatting.
- **AABB Box Collisions:** Lightweight Axis-Aligned Bounding Box (AABB) intersection checking and resolution optimized for grid-based tile structures.

---

## 📐 Architecture & Patterns Used

The structural organization of the engine takes inspiration from foundational literature on game architecture:

- **The Update Method Pattern:** Game elements inherit from a polymorphic baseline interface, updating internal logic frame-by-frame using a calculated time delta.
- **Polymorphic Entity Management:** Uses a central allocation tracker to orchestrate heap lifetime management of runtime active elements utilizing classic C++ pointer arrays.
- **Data-Driven Design:** Leverages absolute separation of engine executable logic from level asset layouts, enabling the creation of new maps without requiring project recompilation.

---

## 🛠️ Tech Stack

- **Language:** C++17
- **Framework & Window Wrapper:** [SFML 3.0](https://www.sfml-dev.org/) (Simple and Fast Multimedia Library)
- **File Parser:** [nlohmann/json](https://github.com/nlohmann/json) (JSON for Modern C++)
- **Build System:** CMake
- **Compiler Toolchain:** MSVC (Visual Studio) / Ninja

---

## 📡 Future Roadmaps & Implementations

- Implement the State Pattern to handle refined player mechanics (Wall jump).
- Implement the Command Pattern to map input actions to physical keyboard events flexibly.
- Incorporate custom sprite-sheet parsing for frame-by-frame 2D texture animation.
- Transition from raw memory allocation tracking to std::unique_ptr smart-pointer lifecycle safety.
- Implement my own rendering pipeline

---

## 🤝 Credits & References

**This project was built following software architecture guidelines and educational breakdowns from:**
- Game Engine Architecture (1st Edition) by Jason Gregory.
- Game Programming Patterns by Robert Nystrom.
- "Fix Your Timestep!" article by Glenn Fiedler (Gaffer on Games).
- Official SFML 3 CMake Template Project.
