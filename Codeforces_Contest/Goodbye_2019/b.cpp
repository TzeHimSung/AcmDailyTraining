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
int t, n, a[maxn];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++) {
            int maxx = a[i], minn = a[i];
            for (int j = i + 1; j <= n; j++) {
                maxx = max(maxx, a[j]), minn = min(minn, a[j]);
                if (maxx - minn >= j - i + 1) {
                    puts("YES");
                    cout << i << " " << j << endl;
                    goto mark;
                }
            }
        }
        puts("NO");
mark:;
    }
    return 0;
}