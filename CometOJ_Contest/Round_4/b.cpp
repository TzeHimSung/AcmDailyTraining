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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        ll l, r, k, L, R;
        scanf("%lld%lld%lld", &l, &r, &k);
        if (k % 2) {
            printf("%lld\n", r - l + 1);
            continue;
        }
        r++;
        if (l < k) L = l;
        else L = l % (k + 1) + l / (k + 1) * k;
        if (r < k) R = r;
        else R = r % (k + 1) + r / (k + 1) * k;
        printf("%lld\n", R - L);
    }
    return 0;
}