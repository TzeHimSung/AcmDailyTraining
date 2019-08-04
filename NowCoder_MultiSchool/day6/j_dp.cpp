#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int INF = 0x3f3f3f3f;
const double eps = 1e-8;
const int maxn = 2100 + 5;
const int mod = 998244353;
ll a[maxn][maxn], sum[maxn];
ll dp[maxn][maxn][20];
int n, m;
void rmq_init() {
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= m + 1; i++)
            dp[j][i][0] = a[j][i]; //初始化
    for (int k = 1; k <= n; k++)
        for (int j = 1; (1 << j) <= m + 1; j++)
            for (int i = 1; i + (1 << j) - 1 <= m + 1; i++)
                dp[k][i][j] = min(dp[k][i][j - 1], dp[k][i + (1 << j - 1)][j - 1]);
}

ll rmq(int j, int l, int r) {
    int k = log2(r - l + 1);
    return min(dp[j][l][k], dp[j][r - (1 << k) + 1][k]);
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 2; j <= m + 1; j++) {
                scanf("%lld", &a[i][j]);
                a[i][j] += a[i][j - 1];
            }
        }
        rmq_init();
        for (int i = 2; i <= m + 1; i++) {
            scanf("%lld", &sum[i]);
            sum[i] += sum[i - 1];
        }
        ll ans = 0;
        for (int j = 1; j <= m + 1; j++) {
            ll tmp1 = 0;
            for (int i = 1; i <= n; i++) {
                tmp1 += rmq(i, j, m + 1);
            }
            //cout<<"!"<<tmp1<<endl;
            for (int i = 1; i <= n; i++) {
                ll tmp = tmp1;
                tmp -= rmq(i, j, m + 1);
                tmp += a[i][j];
                tmp = sum[j] - tmp;
                ans = max(ans, tmp);
            }
        }
        printf("Case #%d: ", ++kase);
        printf("%lld\n", ans);
    }
    return 0;
}