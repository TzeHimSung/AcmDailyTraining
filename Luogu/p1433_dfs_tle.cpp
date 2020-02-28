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

const int maxn = 20;
int n, vis[maxn];
double ans = LONG_LONG_MAX, dis[maxn][maxn], p[maxn][2];

double cal(double _x1, double _y1, double _x2, double _y2) {
    return sqrt((_x1 - _x2) * (_x1 - _x2) + (_y1 - _y2) * (_y1 - _y2));
}

void dfs(int cur, int tot, double len) {
    if (len > ans) return;
    if (tot == n) {
        ans = min(ans, len);
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            dfs(i, tot + 1, len + dis[cur][i]);
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < maxn; i++) vis[i] = 0;
    p[0][0] = p[0][1] = 0;
    for (int i = 1; i <= n; i++) cin >> p[i][0] >> p[i][1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            dis[i][j] = cal(p[i][0], p[i][1], p[j][0], p[j][1]);
        }
    }
    dfs(0, 0, 0.0);
    printf("%.2f\n", ans);
    return 0;
}