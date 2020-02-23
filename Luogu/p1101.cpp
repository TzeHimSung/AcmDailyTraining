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

const string st = "yizhong";
const int maxn = 110;
const int px[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int py[] = {-1, -1, -1, 0, 0, 1, 1, 1};
char s[maxn][maxn];
int n, vis[maxn][maxn];

int check(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

int dfs(int x, int y, int k, int pos) {
    if (st[pos] == 'g') {
        if (s[x][y] == st[pos]) {
            vis[x][y] = 1;
            return 1;
        }
        return 0;
    }
    if (s[x][y] != st[pos]) return 0;
    int newX = x + px[k], newY = y + py[k];
    if (check(newX, newY)) vis[x][y] = max(vis[x][y], dfs(newX, newY, k, pos + 1));
    else return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j] == 'y') {
                for (int k = 0; k < 8; k++) {
                    int newX = i + px[k], newY = j + py[k];
                    if (check(newX, newY)) {
                        vis[i][j] = max(vis[i][j], dfs(newX, newY, k, 1));
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", vis[i][j] ? s[i][j] : '*');
        }
        puts("");
    }
    return 0;
}