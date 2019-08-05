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

const int maxn = 100;
int n, k, d[maxn], u[maxn], tt = 0;

int dfs(int currBit, int low, int hi) {
    if (currBit == n) {
        if (!(--k)) { // 确定是第k小
            vector<int>res;
            for (int i = 0; i < n; i++) res.pb(d[i] - low + 1);
            rep0(i, 0, (int)res.size()) {
                printf("%d", res[i]);
                if (i != (int)res.size() - 1) printf(" "); else puts("");
            }
            return 1;
        }
        return 0;
    }
    for (int i = hi - n + 1; i <= low + n - 1; i++) {
        if (u[i]) continue;
        u[i] = 1; d[currBit] = i;
        if (dfs(currBit + 1, min(low, i), max(hi, i))) {
            u[i] = 0; return 1;
        }
        u[i] = 0;
    }
    return 0;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        tt++;
        scanf("%d%d", &n, &k);
        d[0] = n, u[n] = 1;
        dfs(1, n, n);
        u[n] = 0;
    }
    return 0;
}