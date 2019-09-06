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
#define epre 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
int t, pre[maxn];
char s[maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s + 1);
        int n = strlen(s + 1);
        ll ans = 0;
        rep1(i, 1, n) {
            if (s[i] == '1') pre[i] = -1;
            else pre[i] = s[i - 1] == '0' ? pre[i - 1] : i;
        }
        rep1(r, 1, n) {
            ll curr = 0;
            for (int l = r; l >= 1; l--)
                if (s[l] == '1') {
                    if (r - l >= 20) break;
                    curr += (1 << (r - l));
                    if (r - l + 1 == curr) ans++;
                } else {
                    if (r + 1 - curr >= pre[l] && r + 1 - curr <= l) ans++;
                    l = pre[l];
                }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
