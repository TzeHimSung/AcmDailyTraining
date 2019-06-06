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

const int maxn = 2e5 + 10;
int t;

int main() {
    cin >> t;
    while (t--) {
        int n, k, a[maxn], minn = int_inf, ans = 0;
        cin >> n >> k;
        rep1(i, 1, n) cin >> a[i];
        rep1(i, 1, n - k)
        if (minn > (a[i + k] - a[i] + 1) / 2) {
            minn = (a[i + k] - a[i] + 1) / 2;
            ans = (a[i + k] + a[i]) / 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}