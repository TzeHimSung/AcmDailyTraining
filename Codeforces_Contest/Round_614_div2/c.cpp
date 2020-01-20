/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int a[2][maxn], n, q, wall = 0;

void solve(int x, int y) {
    if (a[x][y]) {
        if (a[x ^ 1][y - 1]) wall--;
        if (a[x ^ 1][y]) wall--;
        if (a[x ^ 1][y + 1]) wall--;
    } else {
        if (a[x ^ 1][y - 1]) wall++;
        if (a[x ^ 1][y]) wall++;
        if (a[x ^ 1][y + 1]) wall++;
    }
    a[x][y] = a[x][y] ^ 1;
}

int main() {
    scanf("%d%d", &n, &q);
    for (int i = 0; i <= n; i++) a[0][i] = a[1][i] = 0;
    while (q--) {
        int x, y; scanf("%d%d", &x, &y);
        x--;
        solve(x, y);
        if (!wall) puts("Yes");
        else puts("No");
    }
    return 0;
}