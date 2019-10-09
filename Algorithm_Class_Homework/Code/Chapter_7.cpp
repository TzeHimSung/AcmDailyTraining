#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

string pattern;

vector<int> generateBadSymbolTable() {
    vector<int> ret;
    int pLen = (int)pattern.size();
    multiset<char>charSet;
    charSet.clear();
    ret.clear();

    for (auto i : pattern) charSet.insert(i);
    charSet.erase(charSet.lower_bound(pattern[pLen - 1]));
    // enumerate each char
    for (int j = 0; j < 26; j++) {
        char currChar = char('a' + j);
        if (!charSet.count(currChar)) ret.emplace_back(pLen);
        else {
            int pos = pLen - 1 - 1;
            while (pos >= 0 && pattern[pos] != currChar) pos--;
            ret.emplace_back(pLen - pos - 1);
        }
    }
    return ret;
}

vector<int> generateGoodSuffixTable() {
    vector<int>ret;
    ret.clear();
    ret.resize(pattern.size() - 1);

    string rePattern = pattern;
    reverse(rePattern.begin(), rePattern.end());
    string currSuffix = "";
    int pLen = (int)pattern.size();

    for (int i = 0; i < pLen - 1; i++) {
        currSuffix += rePattern[i];
        ret[i] = pLen;
        for (int startPos = i + 1; startPos < pLen; startPos++) {
            int _p = 0, _q = startPos;
            while (_q < pLen && _p < (int)currSuffix.size() && rePattern[_q] == currSuffix[_p])
                _p++, _q++;
            if (_q == pLen || _p == (int)currSuffix.size()) {
                ret[i] = startPos;
                break;
            }
        }
    }

    return ret;
}

int main() {
    // init
    cout << "Please input pattern string: ";
    cin >> pattern;
    // generate bad symbol table
    auto badSymbolTable = generateBadSymbolTable();
    // print bad symbol table
    cout << "The bad symbol table is: " << endl;
    for (int i = 0; i < 26; i++) cout << setw(2) << char('a' + i);
    cout << setw(2) << "-";
    cout << endl;
    int cnt = 0;
    for (auto i : badSymbolTable) {
        cout << setw(2) << i;
    }
    cout << setw(2) << pattern.size() << endl;
    // generate good suffix table
    auto goodSuffixTable = generateGoodSuffixTable();
    // print good suffix table
    cout << "The good suffix table is: " << endl;
    cnt = 0;
    cout << "k  distance" << endl;
    for (auto i : goodSuffixTable) {
        cout << ++cnt << "  " << setw(3) << i << endl;
    }

    return 0;
}