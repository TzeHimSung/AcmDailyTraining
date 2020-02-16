/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int t, n;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int>ans;
        while (n--) {
            int x, cnt = 0; scanf("%d", &x);
            while (x) {
                cnt += x & 1;
                x >>= 1;
            }
            ans.pb(cnt);
        }
        for (int i = 0; i < (int)ans.size() - 1; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[(int)ans.size() - 1]);
    }
    return 0;
}