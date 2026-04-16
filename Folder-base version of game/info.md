### What This Program Consists Of

- **Header Files**
  - `<iostream>` → Input and output operations
  - `<cstdlib>` → Random number functions
  - `<ctime>` → Time functions for seeding randomness
  - `<thread>` → Used for delays
  - `<chrono>` → Time duration handling

- **Game Variables**
  - `player` → Stores player position
  - `target` → Stores enemy position
  - `bullet` → Stores bullet position
  - `bulletActive` → Tracks if bullet is active
  - `score` → Stores player score
  - `ch` → Stores user input

- **Game Loop**
  - Infinite loop (`while(true)`) to keep game running
  - Continuously updates screen and logic

- **Rendering System**
  - Prints grid with:
    - `[T]` → Target
    - `[P]` → Player
    - `|` → Bullet

- **Input Handling**
  - Uses `cin` to take movement/shoot commands

- **Game Logic**
  - Movement restrictions within bounds (1–5)
  - Bullet collision detection
  - Score updating system

- **Game Over Condition**
  - When target position equals player position

- **Delay System**
  - Controls game speed using sleep function

- **Randomization**
  - Target appears at random positions each time