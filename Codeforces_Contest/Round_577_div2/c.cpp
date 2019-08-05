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

const int maxn = 2e5 + 10;
ll n, k, a[maxn];

int main() {
    scanf("%lld%lld", &n, &k);
    rep1(i, 1, n) scanf("%lld", &a[i]);
    sot(a, n);
    int cnt = 1;
    for (int i = n / 2 + 1; i < n; i++) {
        if (k / cnt >= a[i + 1] - a[i]) {
            k -= (a[i + 1] - a[i]) * cnt;
            cnt++;
        } else return printf("%lld\n", a[i] + k / cnt), 0;
    }
    printf("%lld\n", a[n] + k / (n / 2 + 1));
    return 0;
}