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

const int maxn = 1e4 + 10, maxm = 5e5 + 10;
const ll INF = (1LL << 31) - 1;

struct Node {
    int index;
    ll w;
    Node() {}
    Node(int a, ll b): index(a), w(b) {}
    bool operator<(const Node &rhs)const {
        return w > rhs.w;
    }
};

struct Edge {
    int v, next;
    ll w;
} edge[maxm];
int n, m, s, head[maxn], vis[maxn], cnt = 0;
ll dis[maxn];

void add(int u, int v, ll w) {
    edge[++cnt].v = v, edge[cnt].w = w;
    edge[cnt].next = head[u], head[u] = cnt;
}

void dijkstra() {
    dis[s] = 0;
    priority_queue<Node>q;
    while (q.size()) q.pop();
    q.push(Node(s, 0));
    while (q.size()) {
        int currPoint = q.top().index;
        q.pop();
        if (vis[currPoint]) continue;
        vis[currPoint] = 1;
        for (int i = head[currPoint]; i; i = edge[i].next) {
            dis[edge[i].v] = min(dis[edge[i].v], dis[currPoint] + edge[i].w);
            if (!vis[edge[i].v]) q.push(Node(edge[i].v, dis[edge[i].v]));
        }
    }
}

int main() {
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= n; i++) {
        head[i] = vis[i] = 0, dis[i] = INF;
    }
    for (int cnt = 1; cnt <= m; cnt++) {
        int u, v; ll w; scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w);
    }
    dijkstra();
    for (int i = 1; i <= n; i++) printf("%lld%c", dis[i], i == n ? '\n' : ' ');
    return 0;
}