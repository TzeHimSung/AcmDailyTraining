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

const int maxn = 30;
int n, a[maxn], b[maxn], v[maxn][maxn], vis[maxn];
ll ans = ll_inf, totCmp = 0;

void dfs(int depth, int curr, ll sum) {
    if (sum >= ans) return;
    if (depth >= n) {
        int b0 = b[0];
        if (b[0] != n)
            for (int i = a[a[0]] + 1; i < 2 * n; i++) {
                for (int j = 1; j <= b[0]; j++) sum += v[i][b[j]];
                b[++b[0]] = i;
            }
        ans = min(ans, sum);
        b[0] = b0;
        return;
    }
    ll addB = 0;
    int a0 = a[0], b0 = b[0];
    rep1(i, curr, n + depth) {
        ll addA = 0;
        rep1(j, 1, a[0]) addA += v[i][a[j]];
        a[++a[0]] = i;
        dfs(depth + 1, i + 1, sum + addA + addB);
        a[0]--;
        rep1(j, 1, b[0]) addB += v[i][b[j]];
        b[++b[0]] = i;
    }
    a[0] = a0, b[0] = b0;
}

int main() {
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    rep0(i, 0, 2 * n) {
        rep0(j, 0, 2 * n)
        scanf("%d", &v[i][j]);
    }
    rep0(i, 0, 2 * n) {
        rep0(j, i + 1, 2 * n) totCmp += v[i][j];
    }
    dfs(0, 0, 0);
    printf("%lld\n", totCmp - ans);
    return 0;
}