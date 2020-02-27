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

const int maxn = 110;
const int px[] {-1, 0, 1, 0};
const int py[] {0, 1, 0, -1};
int n, m, a[maxn][maxn], len[maxn][maxn], ans = 0;

int dfs(int x, int y) {
    if (len[x][y]) return len[x][y];
    len[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + px[i], ny = y + py[i];
        if (1 <= nx && nx <= n && 1 <= ny && ny <= m && a[x][y] > a[nx][ny]) {
            dfs(nx, ny);
            len[x][y] = max(len[x][y], len[nx][ny] + 1);
        }
    }
    return len[x][y];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &a[i][j]);
            len[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            ans = max(ans, dfs(i, j));
        }
    }
    printf("%d\n", ans);
    return 0;
}