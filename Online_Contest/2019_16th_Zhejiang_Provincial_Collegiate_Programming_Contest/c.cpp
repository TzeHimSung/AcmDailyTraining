/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <climits>
#include <float.h>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int n, a[maxn], cnt[maxn], cntTwi[maxn], ans[maxn]; //cntTwi[i]==cnt[i]*2
set<pair<int, int>>s; //次数的两倍和数值makepair，set的特性会先按cnt排序，再按数值排序
set<int>all;

void init(int n)
{
    s.clear(); all.clear();
    rep1(i, 1, n) cnt[i] = cntTwi[i] = ans[i] = 0;
}

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        init(n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            cnt[a[i]]++;
        }
        for (int i = 1; i <= n; i++)
            if (cnt[i])
            {
                all.insert(i);
                s.emplace(cntTwi[i] = 2 * cnt[i], i);
            }
        int flag = 0; //无解标志
        for (int i = 1; !flag && i <= n; i++)
        {
            int p = s.rbegin()->second; //先处理cnt最多而且数值较大的那个数字
            if (cntTwi[p] > n - i + 1) //如果cnt大于剩余位置的一半，必然无解
            {
                flag = 1;
                puts("Impossible");
                break;
            }
            else if (cntTwi[p] < n - i + 1 || p == a[i]) //如果要处理的数字正好for到了，不能放下去，那就找个最小的可用的数字替代之
            {
                auto it = all.begin();
                if (*it == a[i]) it++;
                p = *it;
            }
            //更新re
            s.erase({cntTwi[a[i]], a[i]});
            s.erase({cntTwi[p], p});
            if (--cntTwi[a[i]]) s.emplace(cntTwi[a[i]], a[i]);
            if (--cntTwi[p]) s.emplace(cntTwi[p], p);
            if (--cnt[ans[i] = p] == 0) all.erase(p);
        }
        if (!flag)
            for (int i = 1; i <= n; i++)
                printf("%d%c", ans[i], i < n ? ' ' : '\n');
    }
    return 0;
}