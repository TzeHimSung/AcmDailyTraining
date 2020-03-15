#include <bits/stdc++.h>
using namespace std;
long long dp[2][8];
const long long M = 1e9 + 7;
int main() {
    int n;
    scanf("%d", &n);
    dp[1][0] = dp[1][6] = dp[1][3] = 1;
    for (int i = 2; i <= n; ++i) {
        int now = i & 1;
        int pre = (i - 1) & 1;
        dp[now][7] = (dp[pre][0] + dp[pre][6] + dp[pre][3]) % M;
        dp[now][6] = (dp[pre][1] + dp[pre][7]) % M;
        dp[now][5] = dp[pre][2];
        dp[now][4] = dp[pre][3];
        dp[now][3] = (dp[pre][4] + dp[pre][7]) % M;
        dp[now][2] = dp[pre][5];
        dp[now][1] = dp[pre][6];
        dp[now][0] = dp[pre][7];
        //cout<<dp[now][7]<<endl;
    }
    printf("%lld", dp[n & 1][7]);
}