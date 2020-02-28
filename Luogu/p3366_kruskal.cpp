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

const int maxn = 5050, maxm = 2e5 + 10;
struct Edge {
    int u, v, w;
    bool operator<(const Edge &rhs)const {
        return w < rhs.w;
    }
} edge[maxm];
int n, m, cnt = 0, head[maxn], fa[maxn];

int find(int x) {
    while (x != fa[x]) x = fa[x] = fa[fa[x]];
    return x;
}

int kruskal() {
    int ans = 0, cnt = 0;
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= m; i++) {
        int f1 = find(edge[i].u), f2 = find(edge[i].v);
        if (f1 == f2) continue;
        ans += edge[i].w;
        fa[f1] = f2;
        if (++cnt == n - 1) break;
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    printf("%d\n", kruskal());
    return 0;
}