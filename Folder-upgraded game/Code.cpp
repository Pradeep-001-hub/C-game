#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

void main() {
    int player = 3;
    int bullet = 0;
    int enemies[3];
    int score = 0;
    int speed = 500;
    char ch;

    randomize();

    // Initialize enemies
    for (int i = 0; i < 3; i++) {
        enemies[i] = 1 + random(5);
    }

    clrscr();
    cout << "MULTI ENEMY SHOOTING GAME\n";
    cout << "Use A/D to move, S to shoot\n";
    cout << "Press any key...";
    getch();

    while (1) {
        clrscr();

        // Draw enemies
        for (int i = 1; i <= 5; i++) {
            int found = 0;
            for (int j = 0; j < 3; j++) {
                if (enemies[j] == i) {
                    cout << "[T]";
                    found = 1;
                    break;
                }
            }
            if (!found) cout << "[ ]";
        }
        cout << "\n";

        // Draw bullet
        for (int i = 1; i <= 5; i++) {
            if (i == bullet && bullet != 0)
                cout << " | ";
            else
                cout << "   ";
        }
        cout << "\n";

        // Draw player
        for (int i = 1; i <= 5; i++) {
            if (i == player)
                cout << "[P]";
            else
                cout << "[ ]";
        }
        cout << "\n";

        cout << "Score: " << score << "\n";

        // Bullet movement
        if (bullet != 0) {
            for (int j = 0; j < 3; j++) {
                if (bullet == enemies[j]) {
                    score += 10;
                    enemies[j] = 1 + random(5); // respawn enemy
                    bullet = 0;
                    break;
                }
            }
            if (bullet != 0)
                bullet = 0; // reset if missed
        }

        // Enemy movement (random shift)
        for (int j = 0; j < 3; j++) {
            if (random(2)) {
                if (enemies[j] > 1) enemies[j]--;
            } else {
                if (enemies[j] < 5) enemies[j]++;
            }
        }

        // Input
        if (kbhit()) {
            ch = getch();
            if (ch == 'a' || ch == 'A') {
                if (player > 1) player--;
            }
            if (ch == 'd' || ch == 'D') {
                if (player < 5) player++;
            }
            if (ch == 's' || ch == 'S') {
                bullet = player;
            }
        }

        // Collision (enemy hits player)
        for (int j = 0; j < 3; j++) {
            if (enemies[j] == player) {
                clrscr();
                cout << "GAME OVER!\n";
                cout << "Final Score: " << score;
                getch();
                return;
            }
        }

        // Increase difficulty
        if (score % 50 == 0 && speed > 100) {
            speed -= 50;
        }

        delay(speed);
    }
}
