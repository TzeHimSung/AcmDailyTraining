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

int t, n;
string s;

auto solve(string s) {
    s += '>';
    vector<int>ret;
    for (int i = 0, last = -1; i < n; i++) {
        if (s[i] == '>') {
            for (int j = n - i; j <= n - last - 1; j++) ret.pb(j);
            last = i;
        }
    }
    return ret;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> s;
        auto ans = solve(s);
        for (auto i : ans) cout << i << " \n"[i == ans.back()];
        for (auto &i : s) i ^= '<'^'>';
        ans = solve(s);
        for (auto i : ans) cout << n - i + 1 << " \n"[i == ans.back()];
    }
    return 0;
}
/*
3
3 <<
7 >><>><
5 >>><
1 2 3
1 2 3
7 6 4 5 3 1 2
3 2 1 6 5 4 7
5 4 3 1 2
4 3 2 1 5
 */