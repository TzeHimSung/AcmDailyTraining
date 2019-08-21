/* Codeforces Contest 2019_mutc_10
 * Problem I
 * Au: SJoshua
 */
#include <queue>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool board[2002][2002];
int n, m, q;

const int movement[4][2] = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

struct pos {
    int x, y;
};

int solve(int x, int y) {
    int ans = 0;
    if (board[x][y]) {
        queue <pos> q;
        q.push({x, y});
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (!board[t.x][t.y]) {
                continue;
            }

            ans++;
            board[t.x][t.y] = 0;
            for (int i = 0; i < 4; i++) {
                int nx = t.x + movement[i][0], ny = t.y + movement[i][1];
                if (1 <= nx && nx <= n && 1 <= ny && ny <= m && board[nx][ny]) {
                    if ((!board[nx + 1][ny] || !board[nx - 1][ny]) && (!board[nx][ny - 1] || !board[nx][ny + 1])) {
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
    return ans;
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &q);
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                board[i][j] = true;
            }
        }
        while (q--) {
            int x, y;
            scanf("%d %d", &x, &y);
            printf("%d\n", solve(x, y));
        }
    }
    return 0;
}