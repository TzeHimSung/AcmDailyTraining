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

const int MAXN = 1e6 + 10;
ll height, bottom, top, ans = 0, line[3], dp[MAXN];

int main() {
    while (~scanf("%lld%lld%lld", &height, &bottom, &top)) {
        for (int i = 0; i < MAXN; i++) dp[i] = -1;
        dp[0] = 0, ans = -1;
        for (int i = 0; i < 3; i++) scanf("%lld", &line[i]);
        for (int j = 1; j <= height; j++) {
            for (int i = 0; i < 3; i++) {
                if (line[i] <= j) {
                    ll d = (int)(((double)bottom - (double)(bottom - top) * (double)j / height) / line[i]);
                    if (dp[j - line[i]] >= 0) {
                        dp[j] = max(dp[j], dp[j - line[i]] + (ll)pow(d, 2) * (ll)pow(line[i], 3));
                        ans = max(ans, dp[j]);
                    }
                }
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}