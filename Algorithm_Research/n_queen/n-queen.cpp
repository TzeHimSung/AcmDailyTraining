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
private:

public:
    static bool isAnswer() {

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