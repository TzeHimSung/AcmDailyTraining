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

const int maxn = 1e3 + 10;
struct Edge {
    int u, v, w;
} edge[maxn << 1];
int head[maxn], nxt[maxn << 1], tot = 0, dp[maxn][maxn];

void init() {
    tot = 0;
    rep0(i, 0, maxn) head[i] = 0;
    rep0(i, 0, maxn * 2) nxt[i] = 0;
    rep0(i, 0, maxn) rep0(j, 0, maxn) dp[i][j] = int_inf;
}

void addEdge(int u, int v, int w) {
    nxt[++tot] = head[u];
    head[u] = tot;
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot].w = w;
}

struct Node {
    int x, d, k;
    Node() {}
    Node(int a, int b, int c): x(a), d(b), k(c) {}
    bool operator<(const Node &rhs)const {
        return d > rhs.d;
    }
};

int dijkstra(int s, int t, int k) {
    priority_queue<Node, vector<Node>>q;
    dp[s][k] = 0;
    q.push(Node(s, 0, k));
    while (!q.empty()) {
        Node curr = q.top();
        q.pop();
        int u = curr.x, d = curr.d, k = curr.k;
        if (d > dp[u][k]) continue;
        if (u == t) return d;
        for (int i = head[u]; i; i = nxt[i]) {
            int v = edge[i].v, w = edge[i].w;
            if (k && dp[v][k - 1] > d) {
                dp[v][k - 1] = d;
                q.push(Node(v, d, k - 1));
            }
            if (dp[v][k] > d + w) {
                dp[v][k] = d + w;
                q.push(Node(v, d + w, k));
            }
        }
    }
}

int main() {
    init();
    int n, m, s, t, k; scanf("%d%d%d%d%d", &n, &m, &s, &t, &k);
    rep0(i, 0, m) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        if (u == v) continue;
        addEdge(u, v, w); addEdge(v, u, w);
    }
    printf("%d\n", dijkstra(s, t, k));
    return 0;
}