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

const int maxn = 2e5 + 10;
int n, maxx = 0;
map<string, int>m;
set<string>ss;

int main() {
    cin >> n;
    while (n--) {
        string s; cin >> s;
        m[s]++;
    }
    for (auto i : m) maxx = max(maxx, i.second);
    for (auto i : m)
        if (i.second == maxx) ss.insert(i.first);
    for (auto i : ss) cout << i << endl;
    return 0;
}