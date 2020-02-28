// luogu p3366
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
    int v, w, next;
} edge[maxm << 1]; // 无向图要开两倍空间
int head[maxn], dis[maxn], cnt = 0, n, m, vis[maxn];

void addEdge(int u, int v, int w) {
    edge[++cnt].v = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt;
}

int prim() {
    int tot = 0, currPoint = 1, ans = 0;
    // 选择一号点为根，到其他点的距离都为INF
    for (int i = 2; i <= n; i++) dis[i] = INT_MAX;
    // 更新一号点到其他点的最短距离
    for (int i = head[1]; i; i = edge[i].next)
        dis[edge[i].v] = min(dis[edge[i].v], edge[i].w);
    // 只有n-1条边
    while (++tot < n) {
        int minn = INT_MAX;
        vis[currPoint] = 1;
        // 找到与当前树内点相连的最近的点
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && minn > dis[i]) {
                minn = dis[i];
                currPoint = i;
            }
        }
        ans += minn;
        for (int i = head[currPoint]; i; i = edge[i].next) {
            int v = edge[i].v;
            if (dis[v] > edge[i].w && !vis[v]) dis[v] = edge[i].w;
        }
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) head[i] = vis[i] = 0;
    for (int i = 1, u, v, w; i <= m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w); addEdge(v, u, w);
    }
    printf("%d\n", prim());
    return 0;
}