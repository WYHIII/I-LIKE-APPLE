/************************************************
GAME                I-LIKE-APPLE by WuYuhang
VERSION             0.1.1
DATE(LAST VIEW)     2019.7.25
************************************************/

#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<string>
#include<ctime>
#include<conio.h>
#include<windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getchar;
using std::putchar;

const int X = 100 + 1;
const int Y = 30 + 1;
const int XX = XX / 2;
const int YY = YY / 2;
const int _HP = 100;
const int _MP = 10;

bool m[X+3][Y+3]; //apple

struct Node {
    int x, y;
    int hp, mp, xp;

    Node(int x = XX, int y = YY, int hp = _HP, int mp = _MP, int xp = 0) {
        this->x = x; this->y = y; this->hp = hp; this->mp = mp; this->xp = xp;
    }

    void draw() {
        system("cls");
        for (int y = 1; y < Y; y++) {
            for (int x = 1; x < X; x++) {
                if (y == this->y && x == this->x) {putchar('('); putchar('^'); putchar('_'); putchar('^'); putchar(')');}
                else if (m[x][y]) putchar('*');
                else putchar(' ');
            }
            putchar('\n');
        }

        /*
        for (int i = 1; i < this->y; i++) cout << endl;
        for (int i = 1; i < this->x; i++) cout << ' ';
        cout << "(!)"; */
    }

    void forward(const int &c) {
        draw();

        switch(c) {
            case 'w': case 'W': if (this->y > 1) this->y = this->y - 1; break;
            case 'd': case 'D': if (this->x < X) this->x = this->x + 1; break;
            case 's': case 'S': if (this->y < Y) this->y = this->y + 1; break;
            case 'a': case 'A': if (this->x > 1) this->x = this->x - 1; break;
        }
    }
};

inline void zeroClean() {memset(m, false, sizeof(m));}
inline void hideMouse();
void preGame();

int main() {
    Node Player;
    preGame();

    int c;
    while (c = getch()) {
        Player.forward(c);
    }

    return 0;
}

inline void hideMouse() {   
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void preGame() {
    srand((unsigned)time(NULL));
    zeroClean();
    hideMouse();

    for (int k = 1; k <= X*Y/4; k++) {
        int x1 = rand() / (RAND_MAX / X);
        int y1 = rand() / (RAND_MAX / Y);

        if (!m[x1][y1]) m[x1][y1] = true;
    }
}