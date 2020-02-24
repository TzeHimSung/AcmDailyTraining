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
int n, m, ans[100010], f[maxn][maxn];
char s[maxn][maxn];

void dfs(int x, int y, int val, int num) {
    if (x < 0 || x >= n || y < 0 || y >= n || f[x][y] != -1 || s[x][y] - '0' != val)
        return;
    f[x][y] = num, ans[num]++;
    dfs(x - 1, y, !val, num);
    dfs(x + 1, y, !val, num);
    dfs(x, y - 1, !val, num);
    dfs(x, y + 1, !val, num);
}

int main() {
    memset(f, -1, sizeof(f));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    for (int i = 0; i < m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        x--, y--;
        if (f[x][y] == -1) dfs(x, y, s[x][y] - '0', i);
        else ans[i] = ans[f[x][y]];
    }
    for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
    return 0;
}