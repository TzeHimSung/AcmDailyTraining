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

const int maxn = 1e5 + 10;
vector<int>tree[maxn];
int n;

int dfs(int u, int fa) {
    int ret = 0;
    for (auto v : tree[u]) {
        if (v == fa) continue;
        ret += dfs(v, u);
    }
    ret += ret ? -1 : 1;
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        tree[u].pb(v), tree[v].pb(u);
    }
    printf("%s\n", dfs(1, -1) ? "Alice" : "Bob");
    return 0;
}