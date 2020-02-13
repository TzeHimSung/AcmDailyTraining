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

ll n;

int main() {
    scanf("%lld", &n);
    ll l = 1, r = n;
    while (l <= r) {
        ll mid = l + r >> 1;
        if (mid * (mid + 1) / 2 < n) l = mid + 1;
        else r = mid - 1;
    }
    ll fenzi = n - l * (l - 1) / 2;
    if (l & 1) printf("%lld/%lld", l + 1 - fenzi, fenzi);
    else printf("%lld/%lld", fenzi, l + 1 - fenzi);
    return 0;
}