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
int q, a[maxn];

int cmp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &q);
    while (q--) {
        int n; scanf("%d", &n);
        rep1(i, 1, n) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n, cmp);
        ll ans = a[1], sec = 0, thir = 0;
        int f1 = 0, f2 = 0, f3 = 0;
        for (int i = 2; i <= n && !thir; i++) {
            if (a[1] % a[i]) {
                if (sec) {
                    if (sec % a[i]) {
                        thir = a[i];
                        ans += a[i];
                    }
                } else {
                    sec = a[i];
                    ans += a[i];
                }
            }
            if (a[i] * 2 == a[1]) f1 = 1;
            else if (a[i] * 3 == a[1]) f2 = 1;
            else if (a[i] * 5 == a[1]) f3 = 1;
        }
        if (f1 && f2 && f3) ans = max(ans, (ll)a[1] / 30 * 31);
        printf("%lld\n", ans);
    }
    return 0;
}