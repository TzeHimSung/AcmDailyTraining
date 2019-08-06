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

const int maxn = 10;
int n, k, d[maxn], vis[maxn], tt = 0;

int dfs(int currBit, int lowPoint, int highPoint) {
    if (currBit == n) {
        if (!(--k)) {
            vector<int>ans;
            for (int i = 0; i < n; i++) ans.pb(d[i] - lowPoint + 1);
            rep0(i, 0, (int)ans.size()) {
                printf("%d", ans[i]);
                if (i != (int)ans.size() - 1) printf(" "); else puts("");
            }
            return 1;
        }
        return 0;
    }
    for (int i = highPoint - n + 1; i <= lowPoint + n - 1; i++) {
        if (vis[i]) continue;
        vis[i] = 1; d[currBit] = i;
        if (dfs(currBit + 1, min(lowPoint, i), max(highPoint, i))) {
            vis[i] = 0; return 1;
        }
        vis[i] = 0;
    }
    return 0;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        tt++;
        scanf("%d%d", &n, &k);
        d[0] = n, vis[n] = 1;
        dfs(1, n, n);
        vis[n] = 0;
    }
    return 0;
}