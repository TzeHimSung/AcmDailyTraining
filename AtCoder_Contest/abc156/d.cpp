/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const ll mod = 1e9 + 7;
ll n, a, b;

ll qp(ll x, ll b) {
    ll ret = 1, base = x;
    while (b) {
        if (b & 1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret;
}

ll C(ll n, ll m) {
    if (!m) return 1LL;
    if (m == 1) return n;
    ll ret = 1, maxx = max(m, (n - m)), minn = min(m, (n - m));
    for (ll i = n; i > maxx; i--) ret = ret * i % mod;
    for (ll i = minn; i >= 1; i--) {
        ll currInv = qp(i, mod - 2);
        ret = ret * currInv % mod;
    }
    return ret;
}

int main() {
    cin >> n >> a >> b;
    ll total = (qp(2, n) % mod - 1 % mod + mod) % mod;
    ll c1 = C(n, a) % mod, c2 = C(n, b) % mod;
    ll ans = ((total - c1 + mod) % mod - c2 + mod) % mod;
    cout << ans << endl;
    return 0;
}