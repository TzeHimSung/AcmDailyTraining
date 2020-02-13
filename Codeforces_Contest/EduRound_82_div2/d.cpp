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

ll n, sum;
int t, m, ans;
map<ll, int>cnt;

int main() {
    scanf("%d", &t);
    while (t--) {
        cnt.clear();
        sum = 0, ans = 0;
        scanf("%lld%d", &n, &m);
        for (int i = 0; i < m; i++) {
            ll x; scanf("%lld", &x);
            sum += x; cnt[x]++;
        }
        if (sum < n) {
            puts("-1");
            continue;
        }
        for (int i = 0; i < 63; i++) {
            ll j = 1ll << i;
            if (cnt[j] < ((n >> i) & 1)) {
                ans++;
                cnt[j] += 2;
                cnt[j << 1] -= 1;
            }
            cnt[j << 1] += (cnt[j] - ((n >> i) & 1)) / 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}