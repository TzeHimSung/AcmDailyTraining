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

const int maxn = 2e5 + 10;
int a[maxn], n;
ll ans = 0;

int main()
{
    scanf("%d", &n);
    rep1(i, 1, n) scanf("%d", &a[i]), a[i] = abs(a[i]);
    sot(a, n);
    rep0(i, 1, n) ans += upper_bound(a + i, a + 1 + n, 2 * a[i]) - a - i - 1;
    printf("%lld\n", ans);
    return 0;
}