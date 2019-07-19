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

int n, m;

int main() {
    while (~scanf("%d%d", &n, &m)) {
        int a[n], s1 = 0; ll s2 = 0;
        rep0(i, 0, n) {
            scanf("%d", &a[i]);
            s2 += (ll)a[i] * a[i]; // s2是点到原点欧几里得距离的平方
        }
        sort(a, a + n, greater<int>()); // 从大到小排
        pair<ll, ll> ans(0, 1); // 分数形式
        rep0(i, 0, n) {
            s1 += a[i], s2 -= (ll)a[i] * a[i];
            if (i + 1 == n || (s1 - m) >= (i + 1LL)*a[i + 1]) {
                auto tmp = mp((ll)(s1 - m) * (s1 - m) + (i + 1LL) * s2, i + 1);
                if (tmp.first * ans.second > ans.first * tmp.second)
                    ans = tmp;
            }
        }
        ans.second *= (ll)m * m;
        auto g = __gcd(ans.first, ans.second);
        if (ans.first % ans.second == 0) printf("%lld\n", ans.first / ans.second);
        else printf("%lld/%lld\n", ans.first / g, ans.second / g);
    }
    return 0;
}