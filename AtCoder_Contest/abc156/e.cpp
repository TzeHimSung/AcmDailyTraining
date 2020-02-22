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

const int maxn = 2e5 + 10;
const ll mod = 1e9 + 7;
ll fac[maxn + 1], inv[maxn + 1], dp[maxn + 1], n, k;

ll qp(ll x, ll y = mod - 2) {
    ll ret = 1;
    for (; y; y >>= 1, x = x * x % mod)
        if (y & 1) ret = ret * x % mod;
    return ret;
}

ll C(int x, int y) {
    return fac[x] * inv[y] % mod * inv[x - y] % mod;
}

int main() {
    fac[0] = fac[1] = 1;
    for (int i = 1; i <= maxn; i++) fac[i] = fac[i - 1] * i % mod;
    inv[maxn] = qp(fac[maxn]);
    for (int i = maxn - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
    cin >> n >> k;
    k = min(n - 1, k);
    ll ans = 1;
    for (int i = 1; i <= n; i++) dp[i] = C(n - 1, i - 1);
    for (int i = 1; i <= k; i++) ans = (C(n, i) * dp[n - i] % mod + ans) % mod;
    cout << ans << endl;
    return 0;
}