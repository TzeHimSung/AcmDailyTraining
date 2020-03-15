#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second

int a[10][10], ok = 0;
int w[10][10], quyu[40], num[40];
int rvis[10][10], cvis[10][10], blockvis[10][10], quyuvis[40][10];
inline int getblock(int x, int y) {
    return (x + 1) / 2 * 2 - (y > 3 ? 0 : 1);
}
void dfs(int x, int y) {
    if (y == 7) {
        x++, y = 1;
        dfs(x, y);
        return;
    }
    if (ok)
        return;
    if (x == 7) {
        for (int i = 1; i <= 6; i++)
            for (int j = 1; j <= 6; j++)
                cout << a[i][j] << " \n"[j == 6];
        ok = 1;
        return;
    }

    if (num[w[x][y]] == 1) {
        int v = w[x][y], b = getblock(x, y), p = quyu[v];
        if (!rvis[x][p] && !cvis[y][p] && !blockvis[b][p] && !quyuvis[v][p]) {
            a[x][y] = p;
            quyu[v] = 0, num[v] = 0;
            rvis[x][p] = cvis[y][p] = blockvis[b][p] = quyuvis[v][p] = 1;
            dfs(x, y + 1);
            rvis[x][p] = cvis[y][p] = blockvis[b][p] = quyuvis[v][p] = 0;
            quyu[v] = p, num[v] = 1;
            a[x][y] = 0;
        }
        return;
    }
    for (int i = 1; i <= min(quyu[w[x][y]] - 1, 6); i++) {
        int v = w[x][y], b = getblock(x, y), p = i;
        if (!rvis[x][p] && !cvis[y][p] && !blockvis[b][p] && !quyuvis[v][p]) {
            a[x][y] = p;
            quyu[v] -= p, num[v]--;
            rvis[x][p] = cvis[y][p] = blockvis[b][p] = quyuvis[v][p] = 1;
            dfs(x, y + 1);
            rvis[x][p] = cvis[y][p] = blockvis[b][p] = quyuvis[v][p] = 0;
            quyu[v] += p, num[v]++;
            a[x][y] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> quyu[i];
    for (int i = 1; i <= 6; i++)
        for (int j = 1, x; j <= 6; j++) {
            cin >> x;
            w[i][j] = x, num[x]++;
        }
    dfs(1, 1);
}
