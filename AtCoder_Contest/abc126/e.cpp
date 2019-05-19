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

const int maxn = 1e5 + 10;
int fa[maxn], ans = 0, n, m;

int find(int x)
{
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main()
{
    scanf("%d%d", &n, &m);
    rep1(i, 1, n) fa[i] = i;
    rep1(i, 1, m)
    {
        int x, y, k;
        scanf("%d%d%d", &x, &y, &k);
        int px = find(x), py = find(y);
        fa[px] = py;
    }
    rep1(i, 1, n) if (find(i) == i) ans++;
    printf("%d\n", ans);
    return 0;
}