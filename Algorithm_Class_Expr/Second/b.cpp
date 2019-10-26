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

const int maxn = 30;
int n, m, x, y;
ll a[maxn][maxn], dp[maxn][maxn];

int main() {
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            a[i][j] = dp[i][j] = 0;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    n++, m++, x++, y++;
    // horse blocked
    a[x][y] = 1;
    a[x - 1][y - 2] = a[x - 1][y + 2] = a[x + 1][y - 2] = a[x + 1][y + 2] = 1;
    a[x - 2][y - 1] = a[x - 2][y + 1] = a[x + 2][y - 1] = a[x + 2][y + 1] = 1;
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!a[i][j]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    printf("%lld\n", dp[n][m]);
    return 0;
}