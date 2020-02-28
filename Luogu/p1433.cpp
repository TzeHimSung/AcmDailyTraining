/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const double INF = LONG_LONG_MAX;
const int N = 17, M = 1 << N;
double dis[N][N], point[N][2], dp[M][N];
int n;

double getDis(double x1, double y1, double x2, double y2) {
    double x = x1 - x2;
    double y = y1 - y2;
    return sqrt(x * x + y * y);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lf%lf", &point[i][0], &point[i][1]);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j <= n; ++j) {
            double tem = getDis(point[i][0], point[i][1], point[j][0], point[j][1]);
            dis[i][j] = dis[j][i] = tem;
        }
    n++;
    for (int i = 0; i <= 1 << n; ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = INF;
    dp[1][0] = 0.0;
    for (int i = 0; i < (1 << n); ++i)
        for (int j = 0; j < n; ++j)
            if ((i >> j) & 1) // 如果第j个点到过
                for (int k = 0; k < n; ++k) // 枚举上一个点k
                    if ((i - (1 << j)) >> k & 1)
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + dis[k][j]);
    double ans = INF;
    int allState = (1 << n) - 1;
    for (int i = 1; i < n; ++i) ans = min(ans, dp[allState][i]);
    printf("%.2f", ans);
    return 0;
}