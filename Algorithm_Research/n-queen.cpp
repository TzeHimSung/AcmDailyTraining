// Project: N-queen problem
// Author: JHSeng
// Date: 09/30/2019

// headers

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <utility>

// using standard library

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::pair;
using std::make_pair;

// global variables

int __chessboardSize;
vector<vector<int>> __map;
set<int> __ansSet;

// function declaration

bool isNumber           (string __str);
int  convertStringToInt (string _str);
void solve              ();
void printChessboard    ();
bool checkPosition      (int __curr_x, int __curr_y);
void dfs                (int __filled);
int  getHash            ();

// function achieve

// check current string is number or not
bool isNumber(string __str) {
    for (auto __i : __str) {
        if (__i < '0' || __i > '9') return false;
    }
    return true;
}

// translate string into integer
int convertStringToInt(string __str) {
    int __ret = 0;
    for (auto __i : __str) {
        __ret = __ret * 10 + __i - '0';
    }
    return __ret;
}

// solve n-queen problem
void solve() {
    // chessboard init
    __ansSet.clear();

    __map.resize(__chessboardSize + 1);
    for (auto &__i : __map) {
        for (int __j = 0; __j <= __chessboardSize; __j++) {
            __i.emplace_back(0);
        }
    }

    for (int __i = 1; __i <= __chessboardSize; __i++) {
        for (int __j = 1; __j <= __chessboardSize; __j++) {
            if (checkPosition(__i, __j)) {
                __map[__i][__j] = 1;
                // __queenPos.push_back(make_pair(__i, __j));
                dfs(1);
                __map[__i][__j] = 0;
                // __queenPos.pop_back();
            }
        }
    }
}

// dfs
void dfs(int __filled) {
    if (__filled == __chessboardSize) {
        int __currHash = getHash();
        if (!__ansSet.count(__currHash)) {
            __ansSet.insert(__currHash);
            printChessboard();
        }
        return;
    }
    for (int __i = 1; __i <= __chessboardSize; __i++) {
        for (int __j = 1; __j <= __chessboardSize; __j++) {
            if (checkPosition(__i, __j)) {
                __map[__i][__j] = 1;
                // __queenPos.push_back(make_pair(__i, __j));
                dfs(__filled + 1);
                __map[__i][__j] = 0;
                // __queenPos.pop_back();
            }
        }
    }
}

bool checkPosition(int __curr_x, int __curr_y) {
    bool __ret = true;

    // current point
    if (__map[__curr_x][__curr_y] == 1) __ret = false;

    // total column
    for (int __i = 1; __i <= __chessboardSize; __i++)
        if (__map[__i][__curr_y] == 1) __ret = false;

    // total row
    for (int __j = 1; __j <= __chessboardSize; __j++)
        if (__map[__curr_x][__j] == 1) __ret = false;

    // diagonal
    int __tmp_x = __curr_x, __tmp_y = __curr_y;
    while (__tmp_x - 1 >= 1 && __tmp_y - 1 >= 1)
        __tmp_x--, __tmp_y--;
    while (__tmp_x <= __chessboardSize && __tmp_y <= __chessboardSize)
        if (__map[__tmp_x++][__tmp_y++] == 1) __ret = false;

    __tmp_x = __curr_x, __tmp_y = __curr_y;
    while (__tmp_x - 1 >= 1 && __tmp_y + 1 <= __chessboardSize)
        __tmp_x--, __tmp_y++;
    while (__tmp_x <= __chessboardSize && __tmp_y >= 1)
        if (__map[__tmp_x++][__tmp_y--] == 1) __ret = false;

    return __ret;
}

// print current chessboard
void printChessboard() {
    for (int __i = 1; __i <= __chessboardSize; __i++) {
        for (int __j = 1; __j <= __chessboardSize; __j++) {
            cout << __map[__i][__j] << " ";
        }
        cout << endl;
    }
    cout << "------------------------------------" << endl;
}

int getHash() {
    int __ret = 0;
    for (int __i = 1; __i <= __chessboardSize; __i++) {
        for (int __j = 1; __j <= __chessboardSize; __j++) {
            __ret += __i * __j * __map[__i][__j];
        }
    }
    return __ret;
}

int main() {

    // init chessboard size
    string inputString;
    cout << "Please input the number n, n should be smaller or equal then 10: ";
    cin >> inputString;

    // check whether chessboard size is legal
    while (!isNumber(inputString)) {
        cout << "This input is illegal, please input again";
        cin >> inputString;
    }
    __chessboardSize = convertStringToInt(inputString);

    // solve problem
    solve();

    return 0;
}