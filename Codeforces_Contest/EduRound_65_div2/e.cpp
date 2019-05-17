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

const int maxn = 10;
// const int maxn = 1e6 + 10;
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
    int curr = x, curL = n + 1, curR = 0; //curL从最右边+1开始，rpos从最大的数开始
    while (curr >= 1)
    {
        if (r[curr] < curL) curL = min(curL, l[curr--]); //满足从curr开始递增时，r[curr]也递增
        else
        {
            curr++;
            break;
        }
        pos[curr + 1] = curL; //这好像就是截了一半的数组l
    }
    if (!curr) //如果一直递增，那就可以直接算出来
        return printf("%lld\n", 1LL * x * (x + 1) / 2), 0;
    ll ans = x - curr + 2;
    for (int i = 1; i <= x; i++) //遍历所有数
    {
        curR = max(curR, r[i]); //当前处理过的数的最右出现位置
        while (curL <= curR)
        {
            curr++;
            if (curr == x + 1) curL = n + 1;
            else curL = pos[curr];
        }
        ans += x - curr + 2; //处理不下去就是加上这个表达式？
        if (l[i + 1] <= curR) break; //？？？？
    }
    printf("%lld\n", ans);
    return 0;
}