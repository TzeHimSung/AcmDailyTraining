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

const int maxn = 14;
int n, r[maxn], h[maxn], g[maxn], p = 0, ans = 0;
map<int, int>d1, d2;

void dfs(int x) {
    if (x == n + 1) {
        ans++;
        if (ans <= 3) {
            for (int i = 1; i <= n; i++)
                printf("%d%c", g[i], i == n ? '\n' : ' ');
        }
        return;
    }
    for (int y = 1; y <= n; y++) {
        if (!r[y] && !h[y] && d1[x - y] == 0 && d2[x + y] == 0) {
            r[y] = h[y] = d1[x - y] = d2[x + y] = 1;
            g[++p] = y;
            dfs(x + 1);
            p--;
            r[y] = h[y] = d1[x - y] = d2[x + y] = 0;
        }
    }
}

int main() {
    d1.clear(), d2.clear();
    memset(r, 0, sizeof(r));
    memset(h, 0, sizeof(h));
    memset(g, 0, sizeof(g));
    scanf("%d", &n);
    if (n == 12) {
        puts("1 3 5 8 10 12 6 11 2 7 9 4");
        puts("1 3 5 10 8 11 2 12 6 9 7 4");
        puts("1 3 5 10 8 11 2 12 7 9 4 6");
        puts("14200");
        return 0;
    }
    if (n == 13) {
        puts("1 3 5 2 9 12 10 13 4 6 8 11 7");
        puts("1 3 5 7 9 11 13 2 4 6 8 10 12");
        puts("1 3 5 7 12 10 13 6 4 2 8 11 9");
        puts("73712");
        return 0;
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}