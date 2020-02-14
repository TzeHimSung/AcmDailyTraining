/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

map<string, int>m;
vector<int>a;

int main() {
    a.clear(), m.clear();
    m["one"] = 1; m["two"] = 2; m["three"] = 3; m["four"] = 4; m["five"] = 5; m["six"] = 6; m["seven"] = 7; m["eight"] = 8; m["nine"] = 9; m["ten"] = 10;
    m["eleven"] = 11; m["twelve"] = 12; m["thirteen"] = 13; m["fourteen"] = 14; m["fifteen"] = 15; m["sixteen"] = 16; m["seventeen"] = 17; m["eighteen"] = 18; m["nineteen"] = 19; m["twenty"] = 20;
    m["a"] = 1; m["both"] = 2; m["another"] = 1; m["first"] = 1; m["second"] = 2; m["third"] = 3;
    string s;
    for (int i = 0; i < 6; i++) {
        cin >> s;
        if (!m.count(s)) continue;
        int val = m[s] * m[s] % 100;
        if (val) a.pb(m[s]*m[s] % 100);
    }
    if (a.empty()) return puts("0"), 0;
    sort(a.begin(), a.end());
    for (auto i = a.begin(); i != a.end(); i++) {
        if (i == a.begin()) {
            printf("%d", *i);
            continue;
        }
        if (*i < 10) printf("0");
        printf("%d", *i);
    }
    return 0;
}