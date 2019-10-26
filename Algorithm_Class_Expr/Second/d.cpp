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
#define ll_inf 0x7f77f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1510;
int n, m, k, ans = 0;
int sum[maxn][maxn], leftU[maxn][maxn], leftD[maxn][maxn], rightU[maxn][maxn], rightD[maxn][maxn];
int st1[maxn], st2[maxn];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            scanf("%d", &sum[i][j]);
            sum[i][j] += sum[i][j - 1];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] += sum[i - 1][j];
    for (int i = k; i <= n; i++)
        for (int j = k; j <= m; j++) {
            leftD[i][j] = sum[i][j] + sum[i - k][j - k] - sum[i][j - k] - sum[i - k][j];
            st1[i] = max(st1[i], leftD[i][j]);
            st2[j] = max(st2[j], leftD[i][j]);
            leftD[i][j] = max(leftD[i][j], max(leftD[i - 1][j], leftD[i][j - 1]));
        }
    for (int i = n - k + 1; i; i--)
        for (int j = m - k + 1; j; j--) {
            rightU[i][j] = max(sum[i - 1][j - 1] + sum[i + k - 1][j + k - 1] - sum[i - 1][j + k - 1] - sum[i + k - 1][j - 1], max(rightU[i + 1][j], rightU[i][j + 1]));
        }
    for (int i = k; i <= n; i++)
        for (int j = m - k + 1; j; j--) {
            rightD[i][j] = max(sum[i][j + k - 1] + sum[i - k][j - 1] - sum[i][j - 1] - sum[i - k][j + k - 1], max(rightD[i - 1][j], rightD[i][j + 1]));
        }
    for (int i = n - k + 1; i; i--)
        for (int j = k; j <= m; j++) {
            leftU[i][j] = max(sum[i - 1][j - k] + sum[i + k - 1][j] - sum[i - 1][j] - sum[i + k - 1][j - k], max(leftU[i + 1][j], leftU[i][j - 1]));
        }
    for (int i = k; i < n - k * 2; i++)
        ans = max(ans, rightD[i][1] + st1[i + k] + rightU[i + k + 1][1]);
    for (int i = k; i < m - k * 2; i++)
        ans = max(ans, leftU[1][i] + st2[i + k] + rightU[1][i + k + 1]);
    for (int i = k; i < n - k + 1; i++)
        for (int j = k; j < m - k + 1; j++) {
            ans = max(ans, max(leftD[i][j] + rightD[i][j + 1] + rightU[i + 1][1], rightD[i][1] + leftU[i + 1][j] + rightU[i + 1][j + 1]));
            ans = max(ans, max(leftD[i][j] + leftU[i + 1][j] + rightU[1][j + 1], leftU[1][j] + rightD[i][j + 1] + rightU[i + 1][j + 1]));
        }
    printf("%d\n", ans);
    return 0;
}