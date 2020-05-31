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

const int MAXN = 1010;
string s;
int n, flag = 0, len, ans[MAXN], vis[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s >> n;
    len = s.size();

    function<void(int, int)> dfs = [&](int pos, int lastRemain) {
        // break
        if (pos == len) {
            if (!lastRemain) {
                for (int i = 0; i < len; i++ ) cout << ans[i];
                cout << endl;
                flag = 1;
            }
            return;
        }
        // search
        if (s[pos] == '?') {
            for (int i = 0; i <= 9; i++) {
                // leading zero
                if (!pos && !i) continue;
                ans[pos] = i;
                int curRemain = (lastRemain * 10 + ans[pos]) % n;
                if (!vis[pos + 1][curRemain]) {
                    vis[pos + 1][curRemain] = 1;
                    dfs(pos + 1, curRemain);
                }
                if (flag) return;
            }
        } else {
            ans[pos] = s[pos] - '0';
            int curRemain = (lastRemain * 10 + ans[pos]) % n;
            if (!vis[pos + 1][curRemain]) {
                vis[pos + 1][curRemain] = 1;
                dfs(pos + 1, curRemain);
            }
            if (flag) return;
        }
    };

    dfs(0, 0);
    if (!flag) cout << "*\n";
    return 0;
}