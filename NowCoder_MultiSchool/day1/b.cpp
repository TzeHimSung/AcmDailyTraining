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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int n, a[maxn], c[maxn];

ll qpow(ll n, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * n % mod;
        n = n * n % mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    int inv = qpow(2, mod - 2);
    while (~scanf("%d", &n)) {
        rep1(i, 1, n) scanf("%d", &a[i]);
        rep1(i, 1, n) {
            c[i] = 1;
            rep1(j, 1, n) {
                if (i == j) continue;
                c[i] = (ll)c[i] * (((ll)a[j] * a[j] % mod - (ll)a[i] * a[i] % mod) % mod + mod) % mod;
            }
            c[i] = qpow(c[i], mod - 2);
            c[i] = (ll)c[i] * qpow(a[i], mod - 2) % mod;
            c[i] = (ll)c[i] * inv % mod;
        }
        ll ans = 0;
        rep1(i, 1, n) ans = ((ans + c[i]) % mod + mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}