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

const int maxn = 5e5 + 10;
int n, m, q, times[maxn];
ll a[maxn];

int main() {
    scanf("%d%d%d", &n, &m, &q);
    rep1(i, 1, n) {
        int x; scanf("%d", &x);
        a[i] = (ll)(times[x]++) * m + x;
    }
    sot(a, n);
    rep1(i, 1, n) a[i] -= i;
    while (q--) {
        ll k; scanf("%lld", &k);
        k += lower_bound(a + 1, a + 1 + n, k - n) - a - 1 - n;
        printf("%lld\n", (k - 1) % m + 1);
    }
    return 0;
}