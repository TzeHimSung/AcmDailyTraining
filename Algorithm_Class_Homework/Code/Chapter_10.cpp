// Project: Network flow in undirected Graph (Dinic)
// Author: JHSeng
// Date: 03/12/2018
// Ref: hdu4280

#include <iostream>
#include <queue>

using namespace std;

const int maxn = 10, s = 1, t = 7, n = 7, m = 10;
const int INF = 0x3f3f3f3f;

struct Edge {
    int u, v, flow, next;
    Edge() {}
    Edge(int _u, int _v, int _flow, int _next): u(_u), v(_v), flow(_flow), next(_next) {}
};
// link-forward star
Edge edge[maxn << 1];
int tot = 0, head[maxn], dist[maxn], curArc[maxn];

void addEdge(int u, int v, int flow) {
    edge[tot].u = u;
    edge[tot].v = v;
    edge[tot].flow = flow;
    edge[tot].next = head[u];
    head[u] = tot++;

    edge[tot].u = v;
    edge[tot].v = u;
    edge[tot].flow = flow;
    edge[tot].next = head[v];
    head[v] = tot++;
}

void buildGraph() {
    for (int i = 0; i < maxn; i++) head[i] = -1;
    addEdge(1, 2, 3); addEdge(1, 3, 7);
    addEdge(2, 4, 4); addEdge(2, 5, 5);
    addEdge(3, 4, 6); addEdge(3, 6, 2);
    addEdge(4, 6, 1); addEdge(4, 7, 7);
    addEdge(5, 7, 4); addEdge(6, 7, 4);
}

int bfs() {
    for (int i = 0; i < maxn; i++) dist[i] = -1;
    queue<int>q;
    while (!q.empty()) q.pop();
    dist[1] = 0; q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            if (dist[v] == -1 && edge[i].flow) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist[t] != -1;
}

int dfs(int u, int flow) {
    int ret = 0;
    if (u == t || !flow) return flow;
    for (int &i = curArc[u]; ~i; i = edge[i].next) { // current arc
        int v = edge[i].v;
        if (dist[v] == dist[u] + 1 && edge[i].flow) {
            int d = dfs(v, min(edge[i].flow, flow));
            edge[i].flow -= d;
            edge[i ^ 1].flow += d;
            ret += d; flow -= d; // multiway expand
            if (!flow) break;
        }
    }
    if (!ret) dist[u] = -2; // break point
    return ret;
}

// main function of dinic
int dinic() {
    int ans = 0;
    while (bfs()) {
        for (int i = 1; i <= n; i++) curArc[i] = head[i];
        ans += dfs(s, INF);
    }
    return ans;
}

int main() {
    buildGraph();
    cout << dinic() << endl;
    return 0;
}
