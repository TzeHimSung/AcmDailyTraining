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

int t, n, m;
map<int, int>m1, m2;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ll ans = 0;
        m1.clear(); m2.clear();
        scanf("%d%d", &n, &m); n--;
        rep1(i, 1, m)
        {
            int x; scanf("%d", &x); m1[x]++;
        }
        rep1(i, 1, n)
        {
            rep1(i, 1, m)
            {
                int x; scanf("%d", &x); m2[x]++;
            }
            for (auto i : m2)
            {
                if (m1.count(i.first)) ans += min(i.second, m1[i.first]);
            }
            m1.clear();
            m1 = m2;
            m2.clear();
        }
        printf("%lld\n", ans);
    }
    return 0;
}