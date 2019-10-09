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
```

The result is:

```reStructuredText
Please input pattern string: ababba
The bad symbol table is: 
 a b c d e f g h i j k l m n o p q r s t u v w x y z -
 3 1 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6 6
The good suffix table is: 
k  distance
1    3
2    3
3    5
4    5
5    5
```



### Chapter. 8

Source code:

```c++
#include <iostream>
#include <iomanip>

using namespace std;

const int maxn = 5, maxx = 0x3f3f3f3f;
int dis[maxn][maxn], closure[maxn][maxn];

void printClosure() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << setw(4) << closure[i][j];
        }
        cout << endl;
    }
}

void printDis() {
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            if (dis[i][j] >= maxx) cout << " INF";
            else cout << setw(4) << dis[i][j];
        }
        cout << endl;
    }
}

void buildGraph() {
    // init distance matrix
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            dis[i][j] = i == j ? 0 : maxx;
    // add edge
    dis[1][2] = 2, dis[1][3] = 6, dis[1][4] = 4;
    dis[2][3] = 3;
    dis[3][1] = 7, dis[3][4] = 1;
    dis[4][1] = 5, dis[4][3] = 12;
    // closure matrix init
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            closure[i][j] = (dis[i][j] == maxx || i == j) ? 0 : 1;
}

void warshall() {
    cout << "Initial state:" << endl;
    printClosure();
    // warshall
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                closure[k][j] = (closure[i][j] && closure[k][i]) ? 1 : closure[k][j];
            }
        }
        cout << "i = " << i << ": " << endl;
        printClosure();
        cout << endl;
    }
}

void floyd() {
    // floyd
    for (int k = 1; k <= 4; k++) {
        for (int i = 1; i <= 4; i++) {
            for (int j = 1; j <= 4; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
        cout << "k = " << k << ": " << endl;
        printDis();
        cout << endl;
    }
}

int main() {
    // build graph
    buildGraph();
    // solve
    cout << "Start warshall algorithm." << endl;
    warshall();
    cout << "------------------------------------" << endl;
    cout << "Start floyd algorithm." << endl;
    floyd();
    return 0;
}
```

The result is:

```reStructuredText
Start warshall algorithm.
Initial state:
   0   1   1   1
   0   0   1   0
   1   0   0   1
   1   0   1   0
i = 1: 
   0   1   1   1
   0   0   1   0
   1   1   1   1
   1   1   1   1

i = 2: 
   0   1   1   1
   0   0   1   0
   1   1   1   1
   1   1   1   1

i = 3: 
   1   1   1   1
   1   1   1   1
   1   1   1   1
   1   1   1   1

i = 4: 
   1   1   1   1
   1   1   1   1
   1   1   1   1
   1   1   1   1

------------------------------------
Start floyd algorithm.
k = 1: 
   0   2   6   4
 INF   0   3 INF
   7   9   0   1
   5   7  11   0

k = 2: 
   0   2   5   4
 INF   0   3 INF
   7   9   0   1
   5   7  10   0

k = 3: 
   0   2   5   4
  10   0   3   4
   7   9   0   1
   5   7  10   0

k = 4: 
   0   2   5   4
   9   0   3   4
   6   8   0   1
   5   7  10   0
```

