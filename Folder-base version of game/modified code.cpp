#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// Function to clear screen (portable trick)
void clearScreen() {
    cout << "\033[2J\033[1;1H"; // ANSI escape code
}

int main() {
    int player = 3;
    int bullet = 0;
    int bulletActive = 0;
    int target = rand() % 5 + 1;
    int score = 0;
    char ch;

    srand(time(0));

    cout << "Simple Shooting Game (Modern C++)\n";
    cout << "Use 'a' (left), 'd' (right), 's' (shoot), 'q' (quit)\n";
    cout << "Press Enter to start...";
    cin.get();

    while (true) {
        clearScreen();

        // Draw target row
        for (int i = 1; i <= 5; i++) {
            if (i == target)
                cout << "[T]";
            else
                cout << "[ ]";
        }
        cout << "\n";

        // Draw bullet row
        for (int i = 1; i <= 5; i++) {
            if (i == bullet && bulletActive)
                cout << " | ";
            else
                cout << "   ";
        }
        cout << "\n";

        // Draw player row
        for (int i = 1; i <= 5; i++) {
            if (i == player)
                cout << "[P]";
            else
                cout << "[ ]";
        }
        cout << "\n";

        cout << "Score: " << score << "\n";

        // Bullet logic
        if (bulletActive) {
            if (bullet == target) {
                score++;
                bulletActive = 0;
                target = rand() % 5 + 1;
            } else {
                bulletActive = 0;
            }
        }

        // Input (non-blocking alternative)
        cout << "Enter move: ";
        cin >> ch;

        if (ch == 'a' || ch == 'A') {
            if (player > 1) player--;
        }
        else if (ch == 'd' || ch == 'D') {
            if (player < 5) player++;
        }
        else if (ch == 's' || ch == 'S') {
            bullet = player;
            bulletActive = 1;
        }
        else if (ch == 'q' || ch == 'Q') {
            cout << "Game Quit! Final Score: " << score << endl;
            break;
        }

        // Game over condition
        if (target == player) {
            clearScreen();
            cout << "Game Over! Score: " << score << endl;
            break;
        }

        // Delay for smooth gameplay
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    return 0;
}