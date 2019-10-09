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
    cout << "The bad symbol table is: " << endl;
    cout << "    ";
    for (int i = 0; i < 26; i++) cout << setw(2) << char('a' + i);
    cout << endl;
    int cnt = 0;
    for (auto i : badSymbolTable) {
        cout << setw(2) << cnt++ << "| ";
        for (auto &j : i) cout << setw(2) << j;
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
The bad symbol table is: 
     a b c d e f g h i j k l m n o p q r s t u v w x y z
 0| -1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1
 1|  0-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1
 2|  0 1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1
 3|  2 1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1
 4|  2 3-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1
 5|  2 4-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1
The good suffix table is: 
ababba  -1
 babba  -1
  abba  -1
   bba  -1
    ba   2
     a   2
```



### Chapter. 8

Source code:

```c++
#include <iostream>
#include <iomanip>

using namespace std;

const int maxn = 5, maxx = 0x3f3f3f3f;
int dis[maxn][maxn], closure[maxn][maxn];

void print() {
    cout << "The result of warshall algorithm is:" << endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << setw(4) << closure[i][j];
        }
        cout << endl;
    }
    cout << "The result of floyd algorithm is:" << endl;
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << setw(4) << dis[i][j];
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
            closure[i][j] = (dis[i][j] || i == j) ? 1 : 0;
}

void warshall() {
    // warshall
    for (int i = 1; i <= 4; i++) {
        for (int j = 1; j <= 4; j++) {
            for (int k = 1; k <= 4; k++) {
                closure[k][j] = (closure[i][j] && closure[k][i]) ? 1 : 0;
            }
        }
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
    }
}

int main() {
    // build graph
    buildGraph();
    // solve
    warshall();
    floyd();
    // print answer
    print();
    return 0;
}
```

The result is:

```reStructuredText
The result of warshall algorithm is:
   1   1   1   1
   1   1   1   1
   1   1   1   1
   1   1   1   1
The result of floyd algorithm is:
   0   2   5   4
   9   0   3   4
   6   8   0   1
   5   7  10   0
```

