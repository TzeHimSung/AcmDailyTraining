// Project: N-queen problem (blackboard method)
// Author: JHSeng
// Date: 10/02/2019
// Compiler version: GNU G++ 9.1.0

// headers

#include <bits/stdc++.h>

// using standard library
using namespace std;

// global variables
int __chessboardSize = 0, __numOfAns = 0;
vector<int> __map;

class Chessboard {
private:

    static bool checkDiagram1(int __curr_x, int __curr_y) {
        while (__curr_x - 1 >= 1 && __curr_y - 1 >= 1)
            __curr_x--, __curr_y--;
        int __counter = 0;
        while (__curr_x <= __chessboardSize && __curr_y <= __chessboardSize) {
            __counter += (__map[__curr_x] == __curr_y);
            __curr_x++, __curr_y++;
        }
        if (__counter > 1) return false;
        return true;
    }

    static bool checkDiagram2(int __curr_x, int __curr_y) {
        while (__curr_x - 1 >= 1 && __curr_y + 1 <= __chessboardSize)
            __curr_x--, __curr_y++;
        int __counter = 0;
        while (__curr_x <= __chessboardSize && __curr_y >= 1) {
            __counter += (__map[__curr_x] == __curr_y);
            __curr_x++, __curr_y--;
        }
        if (__counter > 1) return false;
        return true;
    }

public:
    static bool isEmpty(int __curr_x) {
        return __map[__curr_x] == 0;
    }

    static void initChessboard() {
        __map.clear();
        for (int i = 0; i < __chessboardSize; i++)
            __map.emplace_back(0);
    }

    static bool fillChessboard(int __curr_x, int __curr_y) {
        if (__map[__curr_x] != 0) return false;
        __map[__curr_x] = __curr_y;
        return true;
    }

    static bool checkChessboard() {
        // check column
        set<int>__tmpSet;
        __tmpSet.clear();
        for (int __i = 1; __i <= __chessboardSize; __i++)
            __tmpSet.insert(__map[__i]);
        if ((int)__tmpSet.size() != __chessboardSize)
            return false;

        // check diagram
        for (int __i = 1; __i <= __chessboardSize; __i++) {
            if (!Chessboard::checkDiagram1(__i, 1))
                return false;
            if (!Chessboard::checkDiagram2(__i, __chessboardSize))
                return false;
        }
        for (int __j = 1; __j <= __chessboardSize; __j++) {
            if (!Chessboard::checkDiagram1(1, __j))
                return false;
            if (!Chessboard::checkDiagram2(1, __j))
                return false;
        }
        return true;
    }

    static void printChessboard() {
        for (int __i = 1; __i <= __chessboardSize; __i++) {
            for (int __j = 1; __j <= __chessboardSize; __j++) {
                if (__map[__i] == __j) cout << "1 ";
                else cout << "0 ";
            }
        }
    }

};

class Mover {
public:
    static bool moveable() {
        int __ret = false;
        for (int __i = 1; __i <= __chessboardSize; __i++)
            if (Chessboard::isEmpty(__i)) __ret = true;
        return __ret;
    }

    static void move() {
        srand(time(0));
        int __curr_x = rand() % __chessboardSize + 1, __curr_y = rand() % __chessboardSize + 1;
        while (!Chessboard::fillChessboard(__curr_x, __curr_y)) {
            __curr_x = rand() % __chessboardSize + 1, __curr_y = rand() % __chessboardSize + 1;
        }
    }
};

using namespace std;

int main() {
    freopen("input.in", "r", stdin);
    cin >> __chessboardSize;

    Chessboard::initChessboard();
    while (1) {
        if (Mover::moveable())
            Mover::move();
        else
            break;
        if (Chessboard::checkChessboard())
            Chessboard::printChessboard();
    }

    fclose(stdin);
    return 0;
}
