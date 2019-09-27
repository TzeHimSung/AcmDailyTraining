# Homework of algorithm analysis

软工一班 成子谦 201730681303

All codes have been tested under GNU G++ 9.1.0

### Chapter. 7
We can solve this problem by using Boyer-Moore algorithm.  

Source code:

```c++
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
```

The result is:

```reStructuredText
Please input pattern string: ababba
Position | The bad symbol table is: 
         |   a  b  c  d  e  f  g  h  i  j  k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
   0     |  -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
   1     |   0 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
   2     |   0  1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
   3     |   2  1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
   4     |   2  3 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
   5     |   2  4 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
The good suffix table is: 
ababba  -1
 babba  -1
  abba  -1
   bba  -1
    ba   2
     a   2
```

