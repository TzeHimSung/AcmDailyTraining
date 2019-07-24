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
char s[maxn];

int main() {
    int q; scanf("%d", &q);
    while (q--) {
        int n, k; scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        // 0 is g    1 is b   2 is r
        int dp[maxn][3]; dp[0][0] = dp[0][1] = dp[0][2] = 0;
        rep1(i, 1, n) {
            if (s[i - 1] == 'R') {
                if (s[i] == 'G') dp[i][0] = dp[i - 1][2] + 1;
                else dp[i][0] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
            }
            if (s[i - 1] == 'G') {
                if (s[i] == 'B') dp[i][1] = dp[i - 1][0] + 1;
                else dp[i][1] = max(dp[i - 1][1] + 1, dp[i - 1][2] + 1);
            }
            if (s[i - 1] == 'B') {
                if (s[i] == 'R') dp[i][2] = dp[i - 1][1] + 1;
                else dp[i][2] = max(dp[i - 1][2] + 1, dp[i - 1][0] + 1);
            }
        }
        printf("%d\n", k - max(dp[n][1], max(dp[n][2], dp[n][3])));
    }
    return 0;
}