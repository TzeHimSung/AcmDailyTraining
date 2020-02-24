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

const int maxn = 1010;
const int px[] {-1, 0, 1, 0};
const int py[] {0, 1, 0, -1};
int a[maxn][maxn], n, m, vis[maxn][maxn];

int bfs(int x, int y) {
    queue<pair<int, int>>q;
    while (q.size()) q.pop();
    q.push(mp(x, y));
    int ret = 0;
    while (q.size()) {
        auto cur = q.front();
        q.pop();
        if (!vis[cur.first][cur.second]) continue;
        vis[cur.first][cur.second] = 0;
        ret++;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + px[i], ny = cur.second + py[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && vis[nx][ny] == -1 && a[nx][ny] == (a[cur.first][cur.second] ^ 1)) {
                q.push(mp(nx, ny));
            }
        }
    }
    return ret;
}

void bfs2(int x, int y, int v) {
    queue<pair<int, int>>q;
    while (q.size()) q.pop();
    q.push(mp(x, y));
    while (q.size()) {
        auto cur = q.front();
        q.pop();
        vis[cur.first][cur.second] = v;
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + px[i], ny = cur.second + py[i];
            if (1 <= nx && nx <= n && 1 <= ny && ny <= n && vis[nx][ny] == 0) {
                q.push(mp(nx, ny));
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d", &a[i][j]);
            vis[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (vis[i][j] == -1) {
                int result = bfs(i, j);
                bfs2(i, j, result);
            }
        }
    }
    while (m--) {
        int x, y; scanf("%d%d", &x, &y);
        printf("%d\n", vis[x][y]);
    }
    return 0;
}