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

ll b, p, k;

ll qp(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % k;
        a = a * a % k;
        b >>= 1;
    }
    return ret % k;
}

int main() {
    scanf("%lld%lld%lld", &b, &p, &k);
    printf("%lld^%lld mod %lld=%lld\n", b, p, k, qp(b, p));
    return 0;
}