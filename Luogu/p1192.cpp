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

const int MAXN = 1e5 + 10;
int n, k, dp[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    memset(dp, 0, sizeof dp);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = min(i, k); j >= 1; j--) {
            dp[i] += dp[i - j];
            dp[i] = dp[i] > 100003 ? dp[i] % 100003 : dp[i];
        }
    }
    cout << dp[n] << endl;
    return 0;
}