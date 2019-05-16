//via yang12138
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

const int maxn = 1e6 + 10;
int n, x, l[maxn], r[maxn], a[maxn], pos[maxn]; //l[i],r[i]是i在数组中出现的最左最右位置

int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= x; i++) l[i] = n + 1, r[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        l[a[i]] = min(i, l[a[i]]); r[a[i]] = max(i, r[a[i]]);
    }
    int rpos = x, curL = n + 1, curR = 0;
    while (rpos >= 1)
    {
        if (r[rpos] < curL) curL = min(curL, l[rpos--]);
        else
        {
            rpos++;
            break;
        }
        pos[rpos + 1] = curL;
    }
    if (!rpos)
        return printf("%lld\n", 1LL * x * (x + 1) / 2), 0;
    ll ans = x - rpos + 2;
    for (int i = 1; i <= x; i++)
    {
        curR = max(curR, r[i]);
        while (curL <= curR)
        {
            rpos++;
            if (rpos == x + 1) curL = n + 1;
            else curL = pos[rpos];
        }
        ans += x - rpos + 2;
        if (l[i + 1] <= curR) break;
    }
    printf("%lld\n", ans);
    return 0;
}