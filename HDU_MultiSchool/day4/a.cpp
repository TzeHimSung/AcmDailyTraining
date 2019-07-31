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

const int maxn = 2e7;
ll bin[60];
int ans[maxn];

int main() {
    bin[0] = 1;
    for (int i = 1; i <= 40; i++) bin[i] = (bin[i - 1] << 1);
    int T; cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (!(i & 1)) {
                ans[i] = 1;
                continue;
            }
            for (int j = 0; j <= 31; j++) {
                if ((i & bin[j]) == 0) {
                    if (bin[j] <= n) ans[i] = bin[j];
                    else {
                        ans[i] = 1;
                        sum++;
                    }
                    break;
                }
            }
        }
        cout << sum << endl;
        for (int i = 2; i <= n - 1; i++) cout << ans[i] << " ";
        cout << ans[n] << endl;
    }
    return 0;
}