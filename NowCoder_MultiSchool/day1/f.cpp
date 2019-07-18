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

ll p1, q1, p2, q2, p3, q3;

int main() {
    while (~scanf("%lld%lld%lld%lld%lld%lld", &p1, &q1, &p2, &q2, &p3, &q3)) {
        pair<ll, ll> x = mp(p2 - p1, q2 - q1), y = mp(p3 - p1, q3 - q1);
        ll ans = x.first * y.second - y.first * x.second;
        printf("%lld\n", (ll)abs(ans) * 11);
    }
    return 0;
}