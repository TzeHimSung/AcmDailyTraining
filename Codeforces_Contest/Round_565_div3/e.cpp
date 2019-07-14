/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(half,b) sort(half+1,half+1+b)
#define rep1(i,half,b) for(int i=half;i<=b;++i)
#define rep0(i,half,b) for(int i=half;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
int n, m, vis[maxn];
vector<int>adj[maxn], ans, ans1;

void dfs(int x, int depth) {
    if (depth % 2 == 0) ans.pb(x);
    else ans1.pb(x);
    vis[x] = 1;
    rep0(i, 0, adj[x].size()) {
        int y = adj[x][i];
        if (!vis[y]) dfs(y, depth + 1);
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ans.clear(); ans1.clear();
        scanf("%d%d", &n, &m);
        int half = n / 2;
        rep1(i, 1, n) {
            vis[i] = 0; adj[i].clear();
        }
        rep1(i, 1, m) {
            int x, y; scanf("%d%d", &x, &y);
            adj[x].pb(y); adj[y].pb(x);
        }
        dfs(1, 0);
        if (ans.size() <= half) {
            printf("%d\n", (int)ans.size());
            for (auto i : ans) printf("%d ", i);
        } else {
            printf("%d\n", (int)ans1.size());
            for (auto i : ans1) printf("%d ", i);
        }
        puts("");
    }
    return 0;
}