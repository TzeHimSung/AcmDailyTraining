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

const int MAXN = 10;
int n, ans = 0, vis[MAXN], mustPass[MAXN][MAXN], notPass[MAXN][MAXN], path[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 0; i < MAXN; i++) vis[i] = 0;
    notPass[1][3] = notPass[3][1] = notPass[4][6] = notPass[6][4] = notPass[7][9] = notPass[9][7] = 1;
    notPass[1][7] = notPass[7][1] = notPass[2][8] = notPass[8][2] = notPass[3][9] = notPass[9][3] = 1;
    notPass[1][9] = notPass[9][1] = notPass[3][7] = notPass[7][3] = 1;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int u, v; cin >> u >> v;
        mustPass[u][v] = mustPass[v][u] = 1;
    }

    function<int(int)> checkVaild = [&](int depth) {
        int tmp = 0;
        // 必须穿过所有合法路径
        for (int i = 1; i < depth; i++) {
            tmp += mustPass[path[i]][path[i + 1]];
        }
        if (tmp != n) return 0;
        // 不穿过非法路径
        for (int i = 1; i < depth; i++) {
            if (notPass[path[i]][path[i + 1]]) {
                return 0;
            }
        }
        return 1;
    };

    function<void(int)> dfs = [&](int depth) {
        if (depth >= 3) ans = ans + checkVaild(depth - 1);
        if (depth >= 10) return;
        for (int i = 1; i < MAXN; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                path[depth] = i;
                dfs(depth + 1);
                vis[i] = 0;
            }
        }
    };

    dfs(1);

    cout << ans << endl;

    return 0;
}