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
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

ll mulmod(ll x, ll y, ll mod) {
    ll ret = 0; x %= mod; y %= mod;
    while (y) {
        if (y & 1) ret = (ret + x) % mod;
        x = (x << 1) % mod;
        y >>= 1;
    }
    return ret;
}

ll qmul(ll x, ll y, ll p) {
    if (!y) return 1;
    ll tmp = x, ret = 1;
    while (y) {
        if (y & 1) ret = mulmod(ret, tmp, p);
        tmp = mulmod(tmp, tmp, p);
        y = y >> 1;
    }
    return ret;
}

int MillerRobin(ll x) {
    if (x <= 1 || !(x & 1)) return 0;
    if (x == 2) return 1;
    rep1(i, 1, 8) {
        ll rnd = rand() % (x - 2) + 2, k = x - 1;
        while (!(k & 1)) k >>= 1;
        ll tmp = qmul(rnd, k, x);
        while (k != x - 1 && tmp != x - 1 && tmp != 1) {
            tmp = mulmod(tmp, tmp, x);
            k <<= 1;
        }
        if ((tmp == 1 && !(k & 1)) ||  (tmp == x - 1 && k == x - 1) || (tmp != x - 1 && tmp != 1)) return 0;
    }
    return 1;
}

ll qp(ll a, ll b, ll mod) {
    ll ret = 1, base = a;
    while (b) {
        if (b & 1)ret = mulmod(ret, base, mod);
        base = mulmod(base, base, mod);
        b >>= 1;
    }
    return ret;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll n, currPrime; scanf("%lld", &n);
        for (ll i = n - 1; i >= 1; i--) {
            if (MillerRobin(i)) {
                currPrime = i; break;
            }
        }
        ll ans = n - 1;
        for (ll i = currPrime + 1; i < n; i++) ans = mulmod(ans, qp(i, n - 2, n), n);
        printf("%lld\n", ans);
    }
}