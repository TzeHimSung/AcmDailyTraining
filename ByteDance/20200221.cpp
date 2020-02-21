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

const int maxn = 510;
struct Game {
    ll originPrice, currentPrice, happy;
} game[maxn];
int n;
ll x, dp[maxn][10010];
// 合法条件是 sigma(originPrice) - sigma(currentPrice) >= sigma(currentPrice) - x
// sigma(originPrice) - 2sigma(currentPrice) >= - x
// x >= 2 * sigma(currentPrice) - sigma(originPrice)

int main() {
    scanf("%d%lld", &n, &x);
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
        scanf("%lld%lld%lld", &game[i].originPrice, &game[i].currentPrice, &game[i].happy);
    }
    for (int i = 0; i < n; i++) {
        for (ll j = 0; j <= x; j++) {
            if (j >= game[i].currentPrice || j >= 2 * game[i].currentPrice - game[i].originPrice)
                dp[i + 1][j] = max(dp[i][j], dp[i][max(0LL, j - game[i].currentPrice)] + game[i].happy);
            else dp[i + 1][j] = dp[i][j];
        }
    }
    printf("%lld\n", dp[n][x]);
    return 0;
}