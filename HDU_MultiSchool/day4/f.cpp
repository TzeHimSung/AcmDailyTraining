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

const int maxn = 1e4 + 10;
ll dp[55][maxn], sum1[maxn], sum2[maxn], score[maxn];
int a[maxn];

ll X (int i) {
    return sum1[i];
}

ll Y(int t, int i) {
    return dp[t][i] - sum2[i] + i * sum1[i];
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll ans = 0;
        int n, k, m, que[maxn]; scanf("%d%d%d", &n, &k, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum1[i] = sum1[i - 1] + a[i]; sum2[i] = sum2[i - 1] + sum1[i];
            score[i] = (ll)a[i] * (n - i + 1);
        }
        sort(score + 1, score + 1 + n);
        for (int i = n - m + 1; i <= n; i++) ans += score[i];
        memset(dp, 0x3f, sizeof(dp)); dp[0][0] = 0;
        for (int i = 1; i <= k + 1; i++) {
            int head = 0, tail = 0;
            que[tail++] = 0;
            for (int j = 1; j <= n; j++) {
                while (head + 1 < tail && (Y(i - 1, que[head + 1]) - Y(i - 1, que[head]) <= j * (X(que[head + 1]) - X(que[head]))))
                    head++;
                dp[i][j] = dp[i - 1][que[head]] + sum2[j] - sum2[que[head]] - (j - que[head]) * sum1[que[head]];
                while (head + 1 < tail && (Y(i - 1, que[tail - 1]) - Y(i - 1, que[tail - 2])) * (X(j) - X(que[tail - 1])) >= (Y(i - 1, j) - Y(i - 1, que[tail - 1])) * (X(que[tail - 1]) - X(que[tail - 2])))
                    tail--;
                que[tail++] = j;
            }
        }
        ans -= dp[k + 1][n];
        printf("%lld\n", ans);
    }
    return 0;
}