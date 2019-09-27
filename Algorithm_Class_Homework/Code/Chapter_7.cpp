#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

string pattern;

vector<vector<int>> generateBadSymbolTable() {
    vector<vector<int>> ret;
    int pLen = (int)pattern.size();
    ret.resize(pattern.size());
    multiset<char>charSet;
    charSet.clear();

    for (auto i : pattern) charSet.insert(i);
    for (int i = pLen - 1; i >= 0; i--) {
        charSet.erase(charSet.lower_bound(pattern[i]));
        // enumerate each char
        for (int j = 0; j < 26; j++) {
            char currChar = char('a' + j);
            if (!charSet.count(currChar)) ret[i].emplace_back(-1);
            else {
                int pos = i - 1;
                while (pos >= 0 && pattern[pos] != currChar) pos--;
                ret[i].emplace_back(pos);
            }
        }
    }

    return ret;
}

vector<int> generateGoodSuffixTable() {
    vector<int>ret;
    ret.clear();
    ret.resize(pattern.size());

    string rePattern = pattern;
    reverse(rePattern.begin(), rePattern.end());
    string currSuffix = "";
    int pLen = (int)pattern.size();

    for (int i = pLen - 1; i >= 0; i--) {
        currSuffix += pattern[i];
        auto pos = rePattern.find(currSuffix, 1);
        if (pos != string::npos) ret[i] = pLen - pos - 1;
        else ret[i] = -1;
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
    cout << "Position | The bad symbol table is: " << endl;
    cout << "         | ";
    for (int i = 0; i < 26; i++) cout << setw(3) << char('a' + i);
    cout << endl;
    int cnt = 0;
    for (auto i : badSymbolTable) {
        cout << setw(4) << cnt++ << "     | ";
        for (auto &j : i) cout << setw(3) << j;
        cout << endl;
    }
    // generate good suffix table
    auto goodSuffixTable = generateGoodSuffixTable();
    // print good suffix table
    cout << "The good suffix table is: " << endl;
    cnt = 0;
    for (auto i : goodSuffixTable) {
        string currSuffix = pattern.substr(cnt++, int(pattern.size()));
        cout << setw(int(pattern.size())) << currSuffix << " " << setw(3) << i << endl;
    }

    return 0;
}