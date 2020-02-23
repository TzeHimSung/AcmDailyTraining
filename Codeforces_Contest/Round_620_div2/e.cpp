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

const int maxn = 1e5 + 10;
int n, q, f[18][maxn], h[maxn];
vector<int>g[maxn];

void dfs(int x) {
    for (int i = 0; i < (int)g[x].size(); i++) {
        int v = g[x][i];
        if (v == f[0][x]) continue;
        f[0][v] = x;
        h[v] = h[x] + 1;
        dfs(v);
    }
}

int lca(int x, int y) {
    if (h[x] < h[y]) swap(x, y);
    for (int i = 17; i >= 0; i--) {
        if ((h[x] - h[y]) >> i) {
            x = f[i][x];
        }
    }
    if (x == y) return x;
    for (int i = 17; i >= 0; i--) {
        if (f[i][x] != f[i][y]) {
            x = f[i][x], y = f[i][y];
        }
    }
    return f[0][x];
}

int dis(int x, int y) {
    return h[x] + h[y] - h[lca(x, y)] * 2;
}

bool check(int x, int y) {
    return y >= x && ((x & 1) == (y & 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        g[x].pb(y), g[y].pb(x);
    }
    dfs(1);
    for (int i = 1; i <= 17; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        if (check(dis(a, b), k) || check(dis(a, x) + dis(y, b) + 1, k) || check(dis(a, y) + dis(x, b) + 1, k)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}