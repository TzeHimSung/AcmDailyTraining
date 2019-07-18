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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e3 + 10;
const int mod = 1e9 + 7;
int n, m;
ll dp[maxn][maxn];

int main() {
    while (~scanf("%d%d", &n, &m)) {
        // init
        rep1(i, 0, n + m) {
            rep1(j, 0, n + m) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        rep1(i, 0, n + m) {
            rep1(j, 0, n + m) {
                if (i < n || (i - n) < j) // put A
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
                if (j < m || (j - m) < i) // put B
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
            }
        }
        printf("%lld\n", dp[n + m][n + m]);
    }
    return 0;
}