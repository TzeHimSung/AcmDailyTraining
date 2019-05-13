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

int n, m;
ll firLar = 0, secLar = 0, ans, minn = ll_inf, sum1 = 0, sum2 = 0;

int main()
{
    scanf("%d%d", &n, &m);
    rep1(i, 1, n)
    {
        ll x; scanf("%lld", &x);
        if (firLar <= x)
        {
            secLar = firLar;
            firLar = x;
        }
        else if (secLar <= x) secLar = x;
        sum1 += x;
    }
    rep1(i, 1, m)
    {
        ll x; scanf("%lld", &x);
        minn = min(minn, x);
        sum2 += x;
    }
    if (firLar > minn) return puts("-1"), 0;
    ans = sum2 + (sum1 - firLar) * m;
    printf("%lld\n", (firLar < minn) ? ans + firLar - secLar : ans);
    return 0;
}
