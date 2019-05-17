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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 5e3 + 10, mod = 1e9 + 7;
int n, m, a[maxn], f[15][maxn], g[maxn], t = 0, ans = 0;

void add_mod(int &x, int y)
{
    x += y;
    x -= (x >= mod) ? mod : 0;
}

int mi(int x, int y)
{
    x -= y;
    x += (x < 0) ? m : 0;
    return x;
}

int main()
{
    scanf("%d%d", &n, &m); int tmp = m; f[0][0] = 1;
    while (tmp % 2 == 0) t++, tmp >>= 1;   t++;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++) g[j] = f[t][j];
        for (int j = 0; j < m; j++) add_mod(f[t][j], g[mi(j, a[i])]);
        for (int k = t; k; k--)
            for (int j = 0; j < m; j++)
                add_mod(f[k][j], f[k - 1][mi(j, a[i])]);
    }
    for (int i = 0; i < m; i++)
        for (int j = 1; j <= t; j++)
        {
            int x = i;
            for (int k = 1; k < j; k++) x = (x << 1) % m;
            if (!x) add_mod(ans, f[j][i]);
        }
    printf("%d\n", ans);
    return 0;
}