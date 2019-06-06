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

int t;

int main() {
    cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        ll ans = 0;
        while (n) {
            if (n >= k) {
                ans += n % k + 1;
                n /= k;
            } else {
                ans += n % k;
                n = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}