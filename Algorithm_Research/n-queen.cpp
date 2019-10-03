// Project: N-queen problem
// Author: JHSeng
// Date: 09/30/2019

// headers

#include <iostream>
#include <string>
#include <vector>

// using standard library

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

// global variables

vector<vector<int>> __map;

// function declaration

bool isNumber           (string __str);
int  convertStringToInt (string _str);
void solve              (int __chessboardSize);
void printChessboard    ();

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
void solve(int __chessboardSize) {
    // chessboard init
    __map.resize(__chessboardSize + 1);
    for (auto &__i : __map) {
        for (int __j = 0; __j <= __chessboardSize; __j++) {
            __i.emplace_back(0);
        }
    }

    printChessboard();
}

// print current chessboard
void printChessboard() {
    for (auto &__i : __map) {
        for (auto __j : __i) {
            cout << __j << " ";
        }
        cout << endl;
    }
}

int main() {

    // init chessboard size
    string inputString;
    int chessboardSize = 0;
    cout << "Please input the number n, n should be smaller or equal then 10: ";
    cin >> inputString;

    // check whether chessboard size is legal
    while (!isNumber(inputString)) {
        cout << "This input is illegal, please input again";
        cin >> inputString;
    }
    chessboardSize = convertStringToInt(inputString);

    // solve problem
    solve(chessboardSize);

    return 0;
}