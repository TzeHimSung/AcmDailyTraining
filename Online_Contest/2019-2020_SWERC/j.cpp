/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos << 1)
#define rson (curpos << 1 | 1)
/* namespace */
using namespace std;
/* header end */

const ll mod = 1e9 + 7;
const int maxn = 2e6 + 10;
map<int, ll> m;
map<int, vector<int>>pos;
set<int>num;
int n;
ll ans = 1, fac[maxn + 10], inv[maxn + 10];

ll qp(ll a, ll b) {
    ll ret = 1;
    a %= mod;
    while (b) {
        if (b & 1) {
            ret = ret * a % mod;
            b--;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ret;
}

ll C(ll n, ll m) {
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}

ll lucas(ll n, ll m) {
    if (!m) return 1LL;
    return C(n % mod, m % mod) * lucas(n / mod, m / mod) % mod;
}

int main() {
    m.clear();
    fac[0] = 1LL, inv[0] = 1;
    for (ll i = 1; i <= maxn; i++) fac[i] = fac[i - 1] * i % mod;
    inv[maxn] = qp(fac[maxn], mod - 2);
    for (ll i = maxn - 1; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % mod;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        m[x]++; pos[x].pb(i); num.insert(x);
    }
    queue<pair<int, int>>q;
    while (!q.empty()) q.pop();
    q.push(mp(1, n));
    for (auto cur : num) {
        int curl = q.front().first, curr = q.front().second;
        pos[cur]
    }
    printf("%lld\n", ans);

    fclose(stdin);
    return 0;
}