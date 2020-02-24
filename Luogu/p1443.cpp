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

const int maxn = 410;
const int px[] {-1, -2, -2, -1, +1, +2, +2, +1};
const int py[] {-2, -1, +1, +2, +2, +1, -1, -2};
int n, m, x, y, vis[maxn][maxn];

int main() {
    memset(vis, -1, sizeof(vis));
    scanf("%d%d%d%d", &n, &m, &x, &y);
    queue<pair<int, int>>q;
    q.push(mp(x, y));
    vis[x][y] = 0;
    while (q.size()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = cur.first + px[i], ny = cur.second + py[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= m) {
                if (vis[nx][ny] == -1) {
                    vis[nx][ny] = vis[cur.first][cur.second] + 1;
                    q.push(mp(nx, ny));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            printf("%-5d", vis[i][j]);
        puts("");
    }
    return 0;
}