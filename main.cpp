#include <windows.h>
#include <conio.h>
#include <iostream>

struct NODE {
    int x, y;
};

struct SNAKE {
    NODE A[100];
    int Leng;
};

void gotoxy(int column, int line) {
    COORD coord{ SHORT(column), SHORT(line) };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Init(SNAKE& snake) {
    snake.Leng = 7;
    // start vertical, then turn right
    snake.A[0] = { 5, 5 };
    snake.A[1] = { 5, 6 };
    snake.A[2] = { 5, 7 };
    snake.A[3] = { 5, 8 };
    snake.A[4] = { 6, 8 };
    snake.A[5] = { 7, 8 };
    snake.A[6] = { 8, 8 };
}

void Draw(const SNAKE& snake) {
    for (int i = 0; i < snake.Leng; i++) {
        gotoxy(snake.A[i].x * 2, snake.A[i].y);
        std::cout << "##";
    }
    gotoxy(0, 20);
}

void Run(SNAKE& snake, int dir) {
    for (int i = snake.Leng; i > 0; i--)
        snake.A[i] = snake.A[i - 1];

    switch (dir) {
        case 0: snake.A[0].x++; break;
        case 1: snake.A[0].y++; break;
        case 2: snake.A[0].x--; break;
        case 3: snake.A[0].y--; break;
    }

    if (snake.A[0].x < 0)      snake.A[0].x = 39;
    else if (snake.A[0].x > 39) snake.A[0].x = 0;
    if (snake.A[0].y < 0)      snake.A[0].y = 19;
    else if (snake.A[0].y > 19) snake.A[0].y = 0;
}

int main() {
    SNAKE snake;
    Init(snake);
    Draw(snake);

    int dir = 0;
    while (true) {
        if (kbhit()) {
            switch (getch()) {
                case 'd': dir = 0; break;
                case 's': dir = 1; break;
                case 'a': dir = 2; break;
                case 'w': dir = 3; break;
            }
        }
        Run(snake, dir);
        Draw(snake);
        Sleep(200);
    }
    return 0;
}
