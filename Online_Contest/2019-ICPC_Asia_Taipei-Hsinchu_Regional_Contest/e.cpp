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

const int maxn = 1999, lim = 1e6;
ll a[maxn], k, l;

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &k, &l);
        if (l > maxn) {
            puts("-1");
            continue;
        }
        a[0] = -1;
        ll tmp = k + maxn;
        for (int i = 1; i < maxn - 1; i++) {
            a[i] = min(tmp, (ll)lim);
            tmp -= a[i];
        }
        a[maxn - 1] = tmp;
        printf("%d\n%lld", maxn, a[0]);
        for (int i = 1; i < maxn; i++) printf(" %lld", a[i]);
        puts("");
    }
    return 0;
}