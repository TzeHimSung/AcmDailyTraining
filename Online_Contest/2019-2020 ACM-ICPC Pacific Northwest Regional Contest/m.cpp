#include <bits/stdc++.h>
using namespace std;
char Map[2001][2001];
bool vis[2001][2001];
int c[2001][2001];
int cnt = 0;
int mx[] = {0, 0, 1, -1};
int my[] = {1, -1, 0, 0};
void dfs(int x, int y) {
    vis[x][y] = true;
    c[x][y] = cnt;
    for (int i = 0; i < 4; ++i)
        if (!vis[x + mx[i]][y + my[i]] && Map[x + mx[i]][y + my[i]] == '.') {
            dfs(x + mx[i], y + my[i]);
        }
    if (!vis[x - 1][y + 1] && Map[x - 1][y + 1] == '.' && ((Map[x][y + 1] == '.' || Map[x - 1][y] == '.') || (Map[x][y + 1] == '/' && Map[x - 1][y] == '/')) ) dfs(x - 1, y + 1);
    if (!vis[x - 1][y - 1] && Map[x - 1][y - 1] == '.' && ((Map[x][y - 1] == '.' || Map[x - 1][y] == '.') || (Map[x][y - 1] == '\\' && Map[x - 1][y] == '\\'))) dfs(x - 1, y - 1);
    if (!vis[x + 1][y - 1] && Map[x + 1][y - 1] == '.' && ((Map[x][y - 1] == '.' || Map[x + 1][y] == '.') || (Map[x][y - 1] == '/' && Map[x + 1][y] == '/'))) dfs(x + 1, y - 1);
    if (!vis[x + 1][y + 1] && Map[x + 1][y + 1] == '.' && ((Map[x][y + 1] == '.' || Map[x + 1][y] == '.') || (Map[x][y + 1] == '\\' && Map[x + 1][y] == '\\'))) dfs(x + 1, y + 1);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n + 1; ++i) {
        scanf("%s", Map[i] + 2);
    }
    for (int i = 0; i <= n + 3; ++i) {
        Map[i][0] = Map[i][m + 3] = '$';
    }
    for (int i = 0; i <= m + 3; ++i) {
        Map[0][i] = Map[n + 3][i] = '$';
    }
    for (int i = 1; i <= n + 2; ++i) Map[i][1] = Map[i][m + 2] = '.';
    for (int i = 1; i <= m + 2; ++i) Map[1][i] = Map[n + 2][i] = '.';

    int f1 = 0, f2 = 0;
    for (int i = 1; i <= n + 2; ++i)
        for (int j = 1; j <= m + 2; ++j) {
            if (Map[i][j] == '/' && Map[i][j + 1] == '\\' && Map[i + 1][j] == '\\' && Map[i + 1][j + 1] == '/') ++f1;
            if (Map[i][j] == '.' && !vis[i][j]) {
                cnt++;
                dfs(i, j);
                f2++;
            }
        }
    printf("%d", f1 + f2 - 1);
}