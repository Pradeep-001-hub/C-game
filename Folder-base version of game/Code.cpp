#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>

void main() {
    int player = 3;
    int bullet = 0;
    int target = 1 + random(5);
    int score = 0;
    char ch;

    randomize();
    clrscr();
    cout << "Simple Shooting Game in Turbo C++\n";
    cout << "Use 'a' to move left, 'd' to move right, 's' to shoot.\n";
    cout << "Press any key to start...";
    getch();

    while (1) {
        clrscr();

        for (int i = 1; i <= 5; i++) {
            if (i == target)
                cout << "[T]";
            else
                cout << "[ ]";
        }
        cout << "\n";

        for (int i = 1; i <= 5; i++) {
            if (i == bullet && bullet != 0)
                cout << " | ";
            else
                cout << "   ";
        }
        cout << "\n";

        for (int i = 1; i <= 5; i++) {
            if (i == player)
                cout << "[P]";
            else
                cout << "[ ]";
        }
        cout << "\n";

        if (bullet != 0) {
            if (bullet == target) {
                score++;
                bullet = 0;
                target = 1 + random(5);
            } else {
                bullet = 0;
            }
        }

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

        if (target == player) {
            clrscr();
            cout << "Game Over! Score: " << score << "\n";
            break;
        }

        delay(500);
    }

    getch();
}
