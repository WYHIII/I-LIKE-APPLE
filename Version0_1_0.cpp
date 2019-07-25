/************************************************
GAME                I-LIKE-APPLE by WuYuhang
VERSION             0.1.0
DATE(LAST VIEW)     2019.7.25
************************************************/

#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<ctime>
#include<conio.h>
#include<windows.h>

using std::cin;
using std::cout;
using std::endl;

const int X = 100 + 1;
const int Y = 30 + 1;
const int XX = XX / 2;
const int YY = YY / 2;
const int _HP = 100;
const int _MP = 10;

int m[X][Y]; //1 有果实

struct Node {
    int x, y;
    int hp, mp;

    Node(int x = XX, int y = YY, int hp = _HP, int mp = _MP) {
        this->x = x; this->y = y; this->hp = hp; this->mp = mp;
    }

    void draw() {
        system("cls");
        for (int i = 1; i < this->y; i++) cout << endl;
        for (int i = 1; i < this->x; i++) cout << ' ';
        cout << "(!)";
    }

    void forward(const int &c) {
        switch(c) {
            case 'w': case 'W': if (this->y > 1) this->y = this->y - 1; break;
            case 'd': case 'D': if (this->x < X) this->x = this->x + 1; break;
            case 's': case 'S': if (this->y < Y) this->y = this->y + 1; break;
            case 'a': case 'A': if (this->x > 1) this->x = this->x - 1; break;
        }

        draw();
    }
};

void zeroClean();
void preGame();

int main() {
    Node Player;
    preGame();

    int c; Player.draw();
    while (c = getch()) {
        Player.forward(c);
    }


    return 0;
}

void zeroClean() {
    memset(m, 0, sizeof(m));
}

void preGame() {
    srand((unsigned)time(NULL));
    zeroClean();
}