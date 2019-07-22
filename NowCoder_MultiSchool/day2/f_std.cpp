#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int v[30][30];
int n, a[30], b[30];
bool vis[30];
long long ans;
void dfs(int x, int num, long long s) {
    if (s >= ans)return;
    if (x >= n) {
        int b0 = b[0];
        if (b[0] != n)
            for (int i = a[a[0]] + 1; i < 2 * n; i++) {
                for (int o = 1; o <= b[0]; o++)s += v[i][b[o]];
                b[++b[0]] = i;
            }
        ans = min(ans, s);
        b[0] = b0;
        return;
    }
    long long addb = 0;
    int a0 = a[0], b0 = b[0];
    for (int i = num; i < n + x + 1; i++) {
        long long adda = 0;
        for (int o = 1; o <= a[0]; o++)adda += v[i][a[o]];
        a[++a[0]] = i;
        dfs(x + 1, i + 1, s + adda + addb);
        a[0]--;
        for (int o = 1; o <= b[0]; o++)addb += v[i][b[o]];
        b[++b[0]] = i;
    }
    a[0] = a0, b[0] = b0;
}
int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i)
        for (int j = 0; j < 2 * n; ++j)
            scanf("%d", &v[i][j]);
    ans = 1e18;
    long long cmp = 0;
    for (int i = 0; i < 2 * n; i++)
        for (int o = i + 1; o < 2 * n; o++)cmp += v[i][o];

    memset(vis, false, sizeof(vis));
    dfs(0, 0, 0);
    printf("%lld", cmp - ans);
}