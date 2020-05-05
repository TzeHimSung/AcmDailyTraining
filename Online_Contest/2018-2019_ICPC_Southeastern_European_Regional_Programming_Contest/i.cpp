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

const int MAXN = 110;
int n, m, deg[MAXN], _rank[MAXN], vis[MAXN];
ll dp[MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int u, v, i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        u--, v--, deg[min(u, v)]++;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!vis[j])
                if (deg[i]) deg[i]--;
                else {
                    _rank[i] = j;
                    vis[j] = 1;
                    break;
                }
    _rank[n] = n;
    for (int i = 0; i <= n; i++) {
        for (int maxRank = -1, j = i - 1; j >= 0; j--)
            if (_rank[j] > maxRank && _rank[i] > _rank[j])
                maxRank = _rank[j], dp[i] += dp[j];
        dp[i] = max(1LL, dp[i]);
    }
    printf("%lld\n", dp[n]);
    return 0;
}