// Project: N-queen problem (pipe and filter method)
// Author: JHSeng
// Date: 10/01/2019
// Compiler version: GNU G++ 9.1.0

// headers

#include <bits/stdc++.h>

// using standard library

using namespace std;

// global variables

int __chessboardSize, __numOfSolution = 0;
vector<int> __map;
set<int> __ansSet;

class GenerateChessboard {
public:
    // init chessboard
    static void init() {
        __map.clear();
        for (int __i = 0; __i <= __chessboardSize; __i++) {
            __map.emplace_back(1);
        }
    }

    // judge whether the chessboard has next state
    static bool hasNextState() {
        bool __ret = false;
        for (int __i = 1; __i <= __chessboardSize; __i++) {
            if (__map[__i] != __chessboardSize) {
                __ret = true;
                break;
            }
        }
        return __ret;
    }

    // get next state
    static void newMap() {
        int __currPos = __chessboardSize;
        __map[__currPos]++;
        while (__map[__currPos] > __chessboardSize) {
            __map[__currPos] = 1;
            __map[__currPos - 1]++;
            __currPos--;
        }
    }

};

class ChessboardChecker {
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
    static bool isAnswer() {
        // check column
        set<int>__tmpSet;
        __tmpSet.clear();
        for (int __i = 1; __i <= __chessboardSize; __i++)
            __tmpSet.insert(__map[__i]);
        if ((int)__tmpSet.size() != __chessboardSize)
            return false;

        // check diagram
        for (int __i = 1; __i <= __chessboardSize; __i++) {
            if (!ChessboardChecker::checkDiagram1(__i, 1))
                return false;
            if (!ChessboardChecker::checkDiagram2(__i, __chessboardSize))
                return false;
        }
        for (int __j = 1; __j <= __chessboardSize; __j++) {
            if (!ChessboardChecker::checkDiagram1(1, __j))
                return false;
            if (!ChessboardChecker::checkDiagram2(1, __j))
                return false;
        }
        return true;
    }
};

// print chessboard
class ChessboardPrinter {
private:
    // hash current chessboard
    static int getHash() {
        int __ret = 0;
        for (int __i = 1; __i <= __chessboardSize; __i++) {
            for (int __j = 1; __j <= __chessboardSize; __j++) {
                __ret += __i * __j * (__map[__i] == __j ? 1 : 0);
            }
        }
        return __ret;
    }

public:
    static void init() {
        __ansSet.clear();
    }

    static void print() {
        int __currHash = ChessboardPrinter::getHash();
        if (!__ansSet.count(__currHash)) {
            __ansSet.insert(__currHash);

            // print chessboard
            cout << "No. " << ++__numOfSolution << " solution:" << endl;
            for (int __i = 1; __i <= __chessboardSize; __i++) {
                for (int __j = 1; __j <= __chessboardSize; __j++) {
                    if (__map[__i] == __j) cout << "1 ";
                    else cout << "0 ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    // get chessboard size
    freopen("input.in", "r", stdin);
    cin >> __chessboardSize;

    // init
    GenerateChessboard::init();
    ChessboardPrinter::init();

    // enumerate each state of chessboard
    while (GenerateChessboard::hasNextState()) {
        GenerateChessboard::newMap();
        if (ChessboardChecker::isAnswer())
            ChessboardPrinter::print();
    }

    fclose(stdin);

    return 0;
}