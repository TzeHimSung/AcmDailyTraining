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

const int maxn = 110;
ll n, dp[maxn][maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    memset(dp, 0, sizeof(dp));
    dp[0][1] = 1;
    cin >> n;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = i; j <= n + 1; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n + 1][n + 1] << endl;
    return 0;
}