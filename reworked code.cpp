#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <conio.h>
#define CLEAR "cls"
#else
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#define CLEAR "clear"
#endif

using namespace std;

// ----------- Non-blocking input (Linux/Mac) -----------
#ifndef _WIN32
int kbhit() {
    termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

char getch() {
    return getchar();
}
#endif

// ----------- Clear Screen -----------
void clearScreen() {
    system(CLEAR);
}

int main() {
    srand(time(0));

    int player = 3;
    int bullet = -1;
    bool bulletActive = false;

    vector<int> enemies(3);
    for (int &e : enemies)
        e = rand() % 5 + 1;

    int score = 0;
    int speed = 300;
    char ch;

    cout << "MULTI ENEMY SHOOTING GAME (MODERN)\n";
    cout << "A/D = Move | S = Shoot | Q = Quit\n";
    cout << "Press any key to start...\n";

#ifdef _WIN32
    getch();
#else
    getchar();
#endif

    while (true) {
        clearScreen();

        // ----------- Draw Enemies -----------
        for (int i = 1; i <= 5; i++) {
            bool found = false;
            for (int e : enemies) {
                if (e == i) {
                    cout << "[T]";
                    found = true;
                    break;
                }
            }
            if (!found) cout << "[ ]";
        }
        cout << "\n";

        // ----------- Draw Bullet -----------
        for (int i = 1; i <= 5; i++) {
            if (bulletActive && i == bullet)
                cout << " | ";
            else
                cout << "   ";
        }
        cout << "\n";

        // ----------- Draw Player -----------
        for (int i = 1; i <= 5; i++) {
            if (i == player)
                cout << "[P]";
            else
                cout << "[ ]";
        }
        cout << "\n";

        cout << "Score: " << score << "\n";

        // ----------- Input Handling -----------
        if (kbhit()) {
            ch = getch();

            if (ch == 'a' || ch == 'A') {
                if (player > 1) player--;
            }
            else if (ch == 'd' || ch == 'D') {
                if (player < 5) player++;
            }
            else if (ch == 's' || ch == 'S') {
                if (!bulletActive) {
                    bullet = player;
                    bulletActive = true;
                }
            }
            else if (ch == 'q' || ch == 'Q') {
                cout << "Game Quit! Final Score: " << score << endl;
                break;
            }
        }

        // ----------- Bullet Logic -----------
        if (bulletActive) {
            bool hit = false;

            for (int &e : enemies) {
                if (bullet == e) {
                    score += 10;
                    e = rand() % 5 + 1;
                    hit = true;
                    break;
                }
            }

            bulletActive = false;
        }

        // ----------- Enemy Movement -----------
        for (int &e : enemies) {
            if (rand() % 2) {
                if (e > 1) e--;
            } else {
                if (e < 5) e++;
            }
        }

        // ----------- Collision Check -----------
        for (int e : enemies) {
            if (e == player) {
                clearScreen();
                cout << "GAME OVER!\nFinal Score: " << score << endl;
                return 0;
            }
        }

        // ----------- Difficulty Increase -----------
        if (score != 0 && score % 50 == 0 && speed > 100) {
            speed -= 20;
        }

        this_thread::sleep_for(chrono::milliseconds(speed));
    }

    return 0;
}