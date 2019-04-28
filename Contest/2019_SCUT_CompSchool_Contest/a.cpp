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

const int mod = 1e9 + 7;
map<ll, ll>m;
int n;

ll calc(ll x)
{
    if (m.count(x)) return m[x];
    ll res = 0;
    rep1(i, 2, 9)
    {
        if (x >= i) res += calc(x / i) + 1;
    }
    m[x] = res;
    return res;
}

int main()
{
    scanf("%d", &n);
    m[0] = m[1] = 0;
    while (n--)
    {
        ll x, y; scanf("%lld%lld", &x, &y);
        ll ans = (calc(y) - calc(x - 1)) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}