// Project: N-queen problem (pipe and filter method)
// Author: JHSeng
// Date: 10/01/2019
// Compiler version: GNU G++ 9.1.0

// headers

#include <bits/stdc++.h>

// using standard library

using namespace std;

// global variables

int __chessboardSize;
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
public:
    static bool isAnswer() {
        bool __ret = true;
        // check row
        for (int __i = 1; __i <= __chessboardSize; __i++) {
            int __counter = 0;
            for (int __j = 1; __j <= __chessboardSize; __j++) {
                __counter += __map[__i][__j];
            }
            if (__counter >= 2) __ret = false;
        }
        // check column
        for (int __j = 1; __j <= __chessboardSize; __j++) {
            int __counter = 0;
            for (int __i = 1; __i <= __chessboardSize; __i++) {
                __counter += __map[__i][__j];
            }
            if (__counter >= 2) __ret = false;
        }
        // check diagram
        for (int __i = 1; __i <= __chessboardSize; __i++) {
            const int __curr_x = __i, __curr_y = __i;
            int __tmp_x = __curr_x, __tmp_y = __curr_y;
            while (__tmp_x - 1 >= 1 && __tmp_y - 1 >= 1)
                __tmp_x--, __tmp_y--;
            int __counter = 0;
            while (__tmp_x <= __chessboardSize && __tmp_y <= __chessboardSize)
                __counter += __map[__tmp_x++][__tmp_y++];
            if (__counter >= 2) {
                __ret = false;
                break;
            }
        }

        for (int __i = 1; __i <= __chessboardSize; __i++) {
            const int __curr_x = __i, __curr_y = __chessboardSize - __i + 1;
            int __tmp_x = __curr_x, __tmp_y = __curr_y;
            while (__tmp_x - 1 >= 1 && __tmp_y + 1 <= __chessboardSize)
                __tmp_x--, __tmp_y++;
            int __counter = 0;
            while (__tmp_x <= __chessboardSize && __tmp_y >= 1)
                __counter += __map[__tmp_x++][__tmp_y--];

        }
    }
};

// print chessboard
class ChessboardPrinter {
public:
    static void init() {
        __ansSet.clear();
    }

    static void print() {
        int __currHash = getHash();
        if (!__ansSet.count(__currHash)) {
            __ansSet.insert(__currHash);

            // print chessboard
            cout << "No. " << ++__numOfSolution << " solution:" << endl;
            for (int __i = 1; __i <= __chessboardSize; __i++) {
                for (int __j = 1; __j <= __chessboardSize; __j++) {
                    cout << __map[__i][__j] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }

private:
    // hash current chessboard
    int getHash() {
        int __ret = 0;
        for (int __i = 1; __i <= __chessboardSize; __i++) {
            for (int __j = 1; __j <= __chessboardSize; __j++) {
                __ret += __i * __j * __map[__i][__j];
            }
        }
        return __ret;
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

    return 0;
}