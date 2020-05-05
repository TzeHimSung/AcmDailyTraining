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

const int MAXN = 1100;
int n, m, color[MAXN], vis[MAXN];
vector<int>g[MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) scanf("%d", &color[i]);
    for (int u, v, i = 0; i < n - 1; i++) {
        scanf("%d%d", &u, &v);
        g[u].pb(v), g[v].pb(u);
    }

    function<int(int, int, int, int)> dfs = [&](int cur, int fa, int depth, int maxDepth)->int{
        int sum = color[cur];
        if (depth >= maxDepth) return sum;
        for (auto v : g[cur]) {
            if (!vis[v] || v == fa) continue;
            sum += dfs(v, cur, depth + 1, maxDepth);
        }
        return sum;
    };

    function<int(int)> check = [&](int maxDepth)->int{
        memset(vis, 0, sizeof vis);
        queue<int>q;
        while (q.size()) q.pop();
        q.push(1);
        vis[1] = 1;
        while (q.size()) {
            int u = q.front();
            q.pop();
            vis[u] = 1;
            if (dfs(u, 0, 0, maxDepth) >= m) return 1;
            for (auto v : g[u]) {
                if (!vis[v]) q.push(v);
            }
        }
        return 0;
    };

    int l = 0, r = n;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", r);
    return 0;
}