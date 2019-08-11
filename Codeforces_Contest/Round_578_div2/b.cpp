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

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll n, m, k; scanf("%lld%lld%lld", &n, &m, &k);
        ll h[n + 1], solved = 1;
        for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
        for (int i = 1; i < n; i++) {
            if (h[i] >= h[i + 1]) {
                m += h[i] - h[i + 1];
                h[i] = h[i + 1];
                m += min(h[i], k);
            } else {
                if (h[i + 1] - h[i] - m > k) {
                    solved = 0; break;
                } else {
                    if (h[i + 1] - h[i] <= k)
                        m += min(h[i], h[i] - (h[i + 1] - k));
                    else
                        m -= h[i + 1] - h[i] - k;
                }
            }
        }
        if (solved) puts("YES"); else puts("NO");
    }
    return 0;
}