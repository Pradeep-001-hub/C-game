Functions Used & Description

---

Header Files

"<iostream.h>"

- Used for input and output operations
- Provides "cout" for displaying text on screen

"<conio.h>"

- Used for console input/output functions
- Enables real-time keyboard handling

"<dos.h>"

- Used for delay and timing functions
- Helps control game speed

"<stdlib.h>"

- Used for random number generation
- Provides "random()" and "randomize()"

---

functions used
"clrscr()"

- Clears the console screen
- Used every frame to redraw game elements
- Creates illusion of animation

---

"cout"

- Displays output on the screen
- Used to print:
  - Player "[P]"
  - Enemies "[T]"
  - Bullet "|"
  - Score

---

"getch()"

- Takes a key input without pressing Enter
- Used for:
  - Starting the game
  - Reading player controls

---

"kbhit()"

- Checks if a key is pressed
- Prevents the program from stopping (non-blocking input)
- Allows continuous game loop

---

"delay(int time)"

- Pauses execution for given milliseconds
- Controls game speed
- Used to adjust difficulty dynamically

---

"random(int n)"

- Generates a random number from "0" to "n-1"
- Used to:
  - Spawn enemies at random positions
  - Move enemies randomly

---

"randomize()"

- Initializes random seed using system time
- Ensures different random values each run

---

Game Logic Concepts

Game Loop ("while(1)")

- Runs the game continuously
- Updates screen, input, and logic every cycle

---

Collision Detection

- Checks:
  - Bullet hitting enemy → increases score
  - Enemy reaching player → game over

---

Scoring System

- Score increases by 10 points per hit
- Displayed in real-time

---

Difficulty Scaling

- Game speed increases as score grows
- Achieved by reducing delay time

---

Summary

This game uses a combination of:

- Real-time input handling ("kbhit", "getch")
- Screen control ("clrscr")
- Timing ("delay")
- Randomization ("random", "randomize")

to simulate a simple interactive shooting game in a text-based console environment.

---