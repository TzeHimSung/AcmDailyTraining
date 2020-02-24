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

const int maxn = 31;
const int px[] = {-1, 0, 1, 0};
const int py[] = {0, 1, 0, -1};
int n, a[maxn][maxn], vis[maxn][maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            vis[i][j] = 0;
            scanf("%d", &a[i][j]);
        }
    }
    queue<pair<int, int>>q;
    while (q.size()) q.pop();
    for (int i = 1; i <= n; i++) {
        if (a[1][i] == 0) q.push(mp(1, i));
        if (a[n][i] == 0) q.push(mp(n, i));
        if (a[i][1] == 0) q.push(mp(i, 1));
        if (a[i][n] == 0) q.push(mp(i, n));
    }
    while (q.size()) {
        auto cur = q.front();
        q.pop();
        if (vis[cur.first][cur.second]) continue;
        vis[cur.first][cur.second] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + px[i], ny = cur.second + py[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && !vis[nx][ny] && !a[nx][ny]) {
                q.push(mp(nx, ny));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) printf("%d%c", a[i][j], j == n ? '\n' : ' ');
            else if (vis[i][j]) printf("0%c", j == n ? '\n' : ' ');
            else printf("2%c", j == n ? '\n' : ' ');
        }
    }
    return 0;
}