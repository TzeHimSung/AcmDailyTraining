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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

// const int maxn = 3e5 + 10;
const int maxn = 10;
ll a[maxn];
int n, k;

int main() {
    cin >> n >> k;
    rep1(i, 1, n) cin >> a[i];
    for (int i = n; i >= 1; i--) a[i] += a[i + 1];
    // 为什么不sort a[1]，因为数组每个元素都至少被算过一次
    sort(a + 2, a + n + 1);
    reverse(a + 2, a + 1 + n);
    ll ans = 0;
    rep1(i, 1, k) ans += a[i];
    cout << ans << endl;
    return 0;
}