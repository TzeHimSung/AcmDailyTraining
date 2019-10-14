# Homework of algorithm analysis

软工一班 成子谦 201730681303

All codes have been tested under GNU G++ 9.2.0

### Chapter. 9

Source code:

```c++
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>

using namespace std;

struct Edge {
    int to, w;
    Edge() {}
    Edge(int _to, int _w): to(_to), w(_w) {}
};

struct State {
    int index, dis;
    State() {}
    State(int _index, int _dis): index(_index), dis(_dis) {}
    bool operator<(const State &rhs)const {
        return dis > rhs.dis;
    }
};

const int maxn = 10, INF = 0x3f3f3f3f;
int dis[maxn], vis[maxn], cost[maxn][maxn], mincost[maxn];
vector<Edge> g[maxn];
vector<pair<int, int>> path;
map<int, int>m;

void buildUndirectedGraph() {
    g[1].emplace_back(Edge(2, 7)); g[1].emplace_back(Edge(4, 5));
    g[2].emplace_back(Edge(1, 7)); g[2].emplace_back(Edge(4, 9));
    g[2].emplace_back(Edge(3, 8)); g[2].emplace_back(Edge(5, 7));
    g[3].emplace_back(Edge(2, 8)); g[3].emplace_back(Edge(5, 5));
    g[4].emplace_back(Edge(1, 5)); g[4].emplace_back(Edge(5, 15));
    g[4].emplace_back(Edge(6, 6)); g[4].emplace_back(Edge(2, 9));
    g[5].emplace_back(Edge(3, 5)); g[5].emplace_back(Edge(2, 7));
    g[5].emplace_back(Edge(4, 15)); g[5].emplace_back(Edge(6, 8));
    g[5].emplace_back(Edge(7, 9));
    g[6].emplace_back(Edge(4, 6)); g[6].emplace_back(Edge(5, 8));
    g[6].emplace_back(Edge(7, 11));
    g[7].emplace_back(Edge(6, 11)); g[7].emplace_back(Edge(5, 9));
    for (int i = 1; i <= 7; i++)
        for (int j = 1; j <= 7; j++)
            cost[i][j] = INF;
    for (int i = 1; i <= 7; i++) {
        for (auto e : g[i])
            cost[i][e.to] = e.w;
    }
}

void dijkstra(int s) {
    for (int i = 0; i < maxn; i++) dis[i] = INF, vis[i] = 0;
    dis[s] = 0;
    priority_queue<State>q;
    while (!q.empty()) q.pop();
    q.push(State(s, 0));
    while (!q.empty()) {
        int currPoint = q.top().index;
        q.pop();
        if (vis[currPoint]) continue;
        vis[currPoint] = 1;
        for (auto e : g[currPoint]) {
            dis[e.to] = min(dis[e.to], dis[currPoint] + e.w);
            if (!vis[e.to])
                q.push(State(e.to, dis[e.to]));
        }
    }
}

int prim() {
    m.clear();
    for (int i = 0; i < maxn; i++) mincost[i] = INF, vis[i] = 0;
    mincost[1] = 0;
    int ret = 0;
    while (1) {
        int v = -1;
        for (int u = 1; u <= 7; u++) {
            if (!vis[u] && (v == -1 || mincost[u] < mincost[v])) v = u;
        }
        if (v == -1) break;

        vis[v] = 1;
        ret += mincost[v];
        for (int u = 1; u <= 7; u++) {
            if (!vis[u] && mincost[u] > cost[v][u]) {
                mincost[u] = cost[v][u];
                m[u] = v;
            }
        }
    }
    return ret;
}

int main() {
    buildUndirectedGraph();
    // dijkstra
    cout << "The distance table is:" << endl << "S\\T";
    for (int i = 1; i <= 7; i++) cout << setw(3) << char('a' + i - 1);
    cout << endl;
    for (int i = 1; i <= 7; i++) {
        dijkstra(i);
        cout << " " << char('a' + i - 1) << " ";
        for (int j = 1; j <= 7; j++) cout << setw(3) << dis[j];
        cout << endl;
    }
    cout << endl;
    // prim
    cout << "The length of mininum spanning tree is: " << prim() << endl
         << "The MST contains the following edges:" << endl;
    // print MST path
    path.clear();
    for (auto i : m)
        path.emplace_back(make_pair(min(i.first, i.second), max(i.first, i.second)));
    sort(path.begin(), path.end());
    for (auto e : path)
        cout << "From " << char('a' + e.first - 1) << " to " << char('a' + e.second - 1) << endl;
    return 0;
}
```

The result is:

```reStructuredText
The distance table is:
S\T  a  b  c  d  e  f  g
 a   0  7 15  5 14 11 22
 b   7  0  8  9  7 15 16
 c  15  8  0 17  5 13 14
 d   5  9 17  0 14  6 17
 e  14  7  5 14  0  8  9
 f  11 15 13  6  8  0 11
 g  22 16 14 17  9 11  0
 
The length of mininum spanning tree is: 39
The MST contains the following edges:
From a to b
From a to d
From b to e
From c to e
From d to f
From e to g
```



### Chapter. 10

We can solve this problem with Dinic algorithm. This achievement using Current arcs, multiway expand and point-breaking to optimize time complexity.

One thing should be mentioned: the process of adding edges into the undirected graph is different from directed graph.

```c++
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
```

The result is:

```
10
```

