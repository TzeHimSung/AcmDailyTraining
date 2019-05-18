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

const int maxn = 1e2 + 10;
ll n, m, q, a, b, tot = 1, pre[maxn], used[maxn];

int main()
{
    scanf("%d", &q);
    pre[1] = 1;
    rep1(i, 2, 50) //弄个前缀和
    {
        pre[i] = tot;
        tot += pre[i];
    }
    while (q--)
    {
        scanf("%lld%lld%lld", &a, &b, &m);
        bool flag = false;
        rep1(k, 1, 50) //枚举序列长度
        {
            for (int j = k - 1; j > 0; j--) used[j] = 1; //init
            ll curr = pre[k] * a;
            rep0(j, 1, k) curr += pre[j];
            if (curr > b) break; //直接计算最后一项，若不符合，之后都无解
            for (int j = k - 1; j > 0; j--)
            {
                ll l = 0, r = m - 1; //binary search
                while (l <= r)
                {
                    ll mid = l + r >> 1;
                    if (curr + mid * pre[j] > b) r = mid - 1;
                    else l = mid + 1;
                }
                used[j] = --l + 1;
                curr += pre[j] * l;
            }
            if (curr == b) //有解
            {
                flag = true;
                ll curr = a, currsum = 0;
                printf("%d", k);
                rep1(j, 1, k)
                {
                    printf(" %lld", curr);
                    currsum += curr;
                    curr = currsum + used[k - j];
                }
                puts("");
                break;
            }
        }
        if (!flag) puts("-1");
    }
    return 0;
}