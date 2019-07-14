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

int q;
ll n;

int main() {
    cin >> q;
    while (q--) {
        cin >> n; int ans = 0, flag = 1;
        while (n != 1) {
            if (n % 5 == 0) {
                n = n / 5 * 4, ans++; continue;
            } else if (n % 3 == 0) {
                n = n / 3 * 2, ans++; continue;
            } else if (n % 2 == 0) {
                n /= 2, ans++; continue;
            } else {
                flag = 0;
                break;
            }
        }
        if (flag) cout << ans << endl; else puts("-1");
    }
    return 0;
}