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

const int MAXN = 555;
int n, m, d[MAXN], cnt = 0, ans = 999, vis[MAXN][MAXN];
// since max d[x]+d[y] is 999

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    cnt = n * (n - 1) / 2;
    for (int i = 1; i <= m; i++) {
        int s, t; cin >> s >> t;
        d[s]++, d[t]++;
        vis[s][t] = vis[t][s] = 1;
        cnt--;
    }

    function<void(int, int)> solve = [&](int x, int y) {
        if (x > y) swap(x, y);
        d[x]++, d[y]++;
        vis[x][y] = vis[y][x] = 1;
        cnt--;
        for (int i = 1; i <= n; i++) {
            if (i == x || i == y) continue;
            if (!vis[x][i] && d[x] + d[i] >= ans) solve(x, i);
            if (!vis[y][i] && d[y] + d[i] >= ans) solve(y, i);
        }
    };

    while (cnt) {
        ans--;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (!vis[i][j] && d[i] + d[j] >= ans) {
                    solve(i, j);
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}