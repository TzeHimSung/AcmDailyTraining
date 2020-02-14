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

int t;

int main() {
    cin >> t;
    while (t--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int maxA = 0, maxB = 0;
        for (int i = 1; i <= k1; i++) {
            int x; cin >> x; maxA = max(maxA, x);
        }
        for (int i = 1; i <= k2; i++) {
            int x; cin >> x; maxB = max(maxB, x);
        }
        if (maxA > maxB) puts("YES"); else puts("NO");
    }
    return 0;
}
