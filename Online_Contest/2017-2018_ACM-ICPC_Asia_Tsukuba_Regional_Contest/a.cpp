#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second

ll dp[110][3];
int main() {
    int l, k;
    ll ans = 1;
    cin >> l >> k;
    dp[1][0] = dp[k][2] = 1;
    for (int i = 2; i <= l; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][1] = dp[i - 1][0] + dp[i - 1][2];
        if (i - k > 0)
            dp[i][2] = dp[i - k][1];
        ans += dp[i][0] + dp[i][2];
        //cout << dp[i][0] + dp[i][2] << endl;
    }
    cout << ans << endl;
}