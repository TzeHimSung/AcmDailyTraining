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

const int maxn = 2e5 + 10;
int q, cnt[maxn];

int main() {
    scanf("%d", &q);
    while (q--) {
        int n, maxx = 0; scanf("%d", &n);
        rep1(i, 1, n) cnt[i] = 0;
        rep1(i, 1, n) {
            int x; scanf("%d", &x); maxx = max(maxx, x);
            cnt[x]++;
        }
        sot(cnt, maxx);
        ll ans = cnt[maxx]; int last = cnt[maxx];
        for (int i = maxx - 1; i; i--) {
            if (!last || !cnt[i]) break;
            if (cnt[i] >= last) ans += last - 1, last--;
            else ans += cnt[i], last = cnt[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}