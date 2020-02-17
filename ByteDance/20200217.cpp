#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
const int px[4] = {-1, 0, 1, 0}, py[4] = {0, 1, 0, -1};
int n, m, a[maxn][maxn], vis[maxn][maxn];
string ans = "0";

void maintainAns(string cur) {
    if ((int)cur.size() > (int)ans.size()) {
        ans = cur;
        return;
    }
    if ((int)cur.size() < (int)ans.size()) {
        return;
    }
    for (int i = 0; i < (int)ans.size(); i++) {
        if (cur[i] < ans[i]) return;
        if (cur[i] > ans[i]) {
            ans = cur;
            return;
        }
    }
}

bool check(int x, int y) {
    return (1 <= x && x <= n && 1 <= y && y <= m && a[x][y] && !vis[x][y]);
}

void dfs(int curX, int curY, string cur) {
    int flag = 0;
    vis[curX][curY] = 1;
    cur += char(a[curX][curY] + '0');
    for (int i = 0; i < 4; i++) {
        int newX = curX + px[i], newY = curY + py[i];
        if (check(newX, newY)) {
            flag = 1;
            dfs(newX, newY, cur);
        }
    }
    // 如果四个方向都不能走，说明走到头，可以维护答案
    if (!flag) maintainAns(cur);
    vis[curX][curY] = 0;
}

int main() {
    memset(vis, 0, sizeof(vis));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!vis[i][j] && a[i][j]) dfs(i, j, "");
    printf("%s\n", ans.c_str());
    return 0;
}