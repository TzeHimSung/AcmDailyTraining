# Homework of algorithm analysis

软工一班 成子谦 201730681303

All codes have been tested under GNU G++ 9.1.0

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
    m[1] = 1;
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
    // print path
    path.clear();
    m.erase(m.begin());
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

