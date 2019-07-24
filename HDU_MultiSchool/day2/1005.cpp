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

const ll mod = 998244353;

ll qp(ll x, ll b) {
    ll ret = 1, base = x;
    while (b) {
        if (b & 1) ret = ret * base % mod;
        base = base * base % mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    ll n;
    while (~scanf("%lld", &n)) {
        ll k = 0, tmp = 3;
        rep1(i, 2, n) k += tmp, tmp += 2;
        printf("%lld\n", k * qp(9, mod - 2) % mod);
    }
    return 0;
}