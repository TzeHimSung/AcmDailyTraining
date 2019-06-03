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

int n;
const int maxn = 2e3 + 10;
int a[maxn];

int main() {
    cin >> n; n *= 2;
    rep1(i, 1, n) cin >> a[i];
    sot(a, n);
    int sum1 = 0, sum2 = 0;
    rep1(i, 1, n / 2) sum1 += a[i];
    rep1(i, n / 2 + 1, n) sum2 += a[i];
    if (sum1 == sum2) return puts("-1"), 0;
    rep1(i, 1, n) cout << a[i] << " ";
    puts("");
    return 0;
}