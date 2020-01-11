/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define sot(a,mul) sort(a+1,a+1+mul)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curnumber<<1)
#define rson (curnumber<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10, segLim = 10000;
vector<int>a, mul, huzhi[maxn];
int n, cnt[maxn];
ll ans = 0;

void init() {
    ans = 0; a.clear(); mul.clear();
    for (int i = 0; i < maxn; i++) {
        cnt[i] = 0; huzhi[i].clear();
    }
}

int main() {
    while (~scanf("%d", &n)) {
        init();
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            cnt[x]++; a.pb(x);
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        for (int i = 0; i <= segLim; i++) if (cnt[i] >= 2) mul.pb(i);
        for (int i = 1; i <= segLim; i++)
            for (int j = 0; j < (int)mul.size(); j++)
                if (__gcd(i, mul[j]) == 1) huzhi[i].pb(mul[j]);
        // n^2, enum shang di && xia di
        for (int i = 0; i < (int)a.size(); i++) {
            for (int j = i + 1; j < (int)a.size(); j++) {
                int gcd = __gcd(a[i], a[j]);
                int curr = 0;
                if ((a[j] - a[i]) % 2 == 0) curr = (a[j] - a[i]) / 2 + 1;
                else curr = (a[j] - a[i] + 1) / 2;
                int number = lower_bound(huzhi[gcd].begin(), huzhi[gcd].end(), curr) - huzhi[gcd].begin();
                ans += (int)huzhi[gcd].size() - number;
                if (gcd == 1) {
                    if (a[i] >= curr && cnt[a[i]] == 2) ans--;
                    if (a[j] >= curr && cnt[a[j]] == 2) ans--;
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
