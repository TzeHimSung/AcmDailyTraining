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

const int maxn = 1e6 + 10;
int p, q, n, a[maxn], dp[maxn], reachable[maxn];

int main() {
    scanf("%d%d%d", &p, &q, &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < maxn; i++) dp[i] = reachable[i] = 0;
    if (p < q) return puts("NO"), 0;
    reachable[0] = 1;
    dp[0] = p, dp[1] = p - q + a[1];
    reachable[1] = dp[1] < q ? 0 : 1;
    for (int i = 2; i <= n; i++) {
        if (!reachable[i - 1] && !reachable[i - 2]) return puts("NO"), 0;
        if (reachable[i - 1] && !reachable[i - 2])
            dp[i] = dp[i - 1] - q + a[i];
        else if (!reachable[i - 1] && reachable[i - 2])
            dp[i] = dp[i - 2] - q + a[i];
        else
            dp[i] = max(dp[i - 1], dp[i - 2]) - q + a[i];
        if (dp[i] >= q) reachable[i] = 1;
    }
    int ans = 0;
    if (!reachable[n] && !reachable[n - 1]) return puts("NO"), 0;
    else if (reachable[n] && !reachable[n - 1]) ans = dp[n] - q;
    else if (!reachable[n] && reachable[n - 1]) ans = dp[n - 1] - q;
    else ans = max(dp[n], dp[n - 1]) - q;
    printf("%d\n", ans);
    return 0;
}