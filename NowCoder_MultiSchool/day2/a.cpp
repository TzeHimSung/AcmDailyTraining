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

const ll mod = 1e9 + 7;

ll qp(ll x, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * x % mod;
        x = x * x % mod;
        b >>= 1;
    }
    return ret;
}

ll n, m, ans = 1;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &n, &m);
        if (n == 1) printf("%lld\n", ans);
        else {
            if (!m) ans = 0;
            else ans = ans * qp(n - 1, mod - 2) % mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}