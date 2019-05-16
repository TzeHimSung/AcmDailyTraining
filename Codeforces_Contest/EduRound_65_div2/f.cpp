/* basic header */
#include <bits/stdc++.h>
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
const int maxn = 5e5 + 10;
ll a[maxn], b[maxn], c[maxn], ans = 0;
int n;

void addmod(ll &a, ll b)
{
    a += b;
    if (a >= mod) a -= mod;
    if (a < 0) a += mod;
}

void add(int u, int val)
{
    for (; u <= n; u += u & -u) addmod(c[u], val);
}

ll sum(int u)
{
    ll ret = 0;
    for (; u > 0; u -= u & -u) addmod(ret, c[u]);
    return ret;
}

int id(int x)
{
    return lower_bound(b, b + n, x) - b + 1;
}

ll solve()
{
    rep1(i, 1, n) c[i] = 0;
    ll ans = 0;
    rep0(i, 0, n)
    {
        ll curr = sum(id(a[i]));
        addmod(ans, (a[i] * curr % mod) * (n - i) % mod);
        add(id(a[i]), i + 1);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    rep0(i, 0, n) scanf("%lld", &a[i]), b[i] = a[i];
    sort(b, b + n);
    rep0(i, 0, n)
    addmod(ans, a[i] * (i + 1) % mod * (n - i) % mod);
    addmod(ans, solve());
    reverse(a, a + n);
    addmod(ans, solve());
    printf("%lld\n", ans);
    return 0;
}