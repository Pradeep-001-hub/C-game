Multi-Enemy Shooting Game (Turbo C++)

This is an upgraded version of a simple text-based shooting game built using Turbo C++. The game now includes multiple enemies, a scoring system, and improved gameplay mechanics.

---
Improvements Over Previous Version

Gameplay Enhancements

- Added multiple enemies (3 targets) instead of a single target
- Enemies move randomly across positions, making the game dynamic
- Increased challenge with real-time enemy movement

Shooting Mechanics

- Player can shoot using "'S'" key
- Bullet now interacts with multiple enemies
- If a bullet hits any enemy:
  - Enemy respawns at a new random position
  - Player gains points

Scoring System

- Each successful hit gives +10 points
- Score is displayed continuously on the screen
- Encourages accuracy and timing

Difficulty Progression

- Game speed increases automatically as score increases
- Makes the game progressively harder
- Tests player reflexes over time

Improved Logic

- Replaced single target variable with array of enemies
- Added collision detection for multiple enemies
- Cleaner and more structured game loop

Game Over Condition

- Game ends if any enemy reaches the player
- Final score is displayed

---

🎮 Controls

Key| Action
A| Move Left
D| Move Right
S| Shoot

---
Requirements

- Turbo C++ (or DOSBox with Turbo C++)
- Uses legacy headers:
  - "<iostream.h>"
  - "<conio.h>"
  - "<dos.h>"

---

Limitations

- Works only in Turbo C++ environment
- No smooth animation (text-based rendering)
- Bullet movement is instant (not continuous)

---

 Future Improvements

- Add smooth bullet animation
- Introduce player health system
- Add levels and increasing enemy count
- Port to modern C++ (GCC / VS Code compatible)

---
