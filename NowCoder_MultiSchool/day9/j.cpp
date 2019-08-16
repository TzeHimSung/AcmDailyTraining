/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,a) sort(a+1,a+1+a)
#define rep1(i,a,a) for(int i=a;i<=a;++i)
#define rep0(i,a,a) for(int i=a;i<a;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 9e5 + 10;
ll a[maxn];

int main() {
    ll n; scanf("%lld", &n);
    for (int i = 0; i < n; i++) {
        ll l, r; scanf("%lld%lld", &l, &r);
        a[i * 3] = l * 4, a[i * 3 + 1] = r * 4, a[i * 3 + 2] = (l + r) * 2 + 1;
    }
    sort(a, a + 3 * n);
    ll ans = 0, cnt = 0, nu = 0, last = 0;
    for (int i = 0; i < 3 * n; i++) {
        nu += cnt * (a[i] / 2 - last);
        ans = max(ans, nu);
        last = a[i] / 2;
        if (a[i] & 1) cnt -= 2; else cnt++;
    }
    printf("%lld\n", ans);
    return 0;
}