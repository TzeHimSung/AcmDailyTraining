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

const int mod = 998244353, maxn = 1e5 + 10;
int n;
ll P, x, y, ans, fac[maxn], inv[maxn];

ll quickPow(ll x, ll y = mod - 2)
{
    ll ret = 1;
    for (; y; y >>= 1, x = x * x % mod)
        if (y & 1) ret = ret * x % mod;
    return ret;
}

ll C(int x, int y)
{
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}

int main()
{
    fac[0] = 1;
    scanf("%d%lld%lld", &n, &x, &y);
    P = x * quickPow(y) % mod;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
    inv[n] = quickPow(fac[n]);
    for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    for (int i = 0; i <= n; i++)
        ans = (ans + C(n, i) * quickPow(P, (ll)i * (i - 1) / 2)) % mod;
    printf("%lld\n", ans);
    return 0;
}