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

const int maxn = 1010;
const double pi = acos(-1);
vector<pair<double, double>>ans;
vector<int>g[maxn];
int n, __size[maxn];

void dfs(int u, int father, double angle) {
    __size[u]++;
    for (auto v : g[u]) {
        if (v != father) {
            ans[v].first = ans[u].first + cos(angle);
            ans[v].second = ans[u].second + sin(angle);
            dfs(v, u, angle);
            __size[u] += __size[v];
            angle += pi / maxn * __size[v];
        }
    }
}

int main() {
    scanf("%d", &n);
    ans.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        g[u].pb(v), g[v].pb(u);
    }
    dfs(1, -1, 0);
    for (int i = 1; i <= n; i++) printf("%.10f %.10f\n", ans[i].first, ans[i].second);
    return 0;
}