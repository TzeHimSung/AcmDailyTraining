#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> edges[100001];
vector<pair<int, int>> rev_edges[100001];
struct node {
    int x;
    long long val;
    node() {}
    node(int _x, long long _val) {
        x = _x;
        val = _val;
    }
    bool operator<(const node &b) const {
        return val > b.val;
    }
};
struct edge {
    int u, v, w;
    edge() {}
    edge(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }
};
vector<edge> eds;
void dijkstra(int s, vector<pair<int, int>> edges[], long long dis[], int n) {
    priority_queue<node> que = priority_queue<node>();
    bool vis[200001];
    for (int i = 1; i <= n; ++i) {
        vis[i] = false;
        dis[i] = 99999999999;
    }
    dis[s] = 0;
    que.push(node(s, 0));
    while (!que.empty()) {
        node tmp = que.top();
        que.pop();
        if (vis[tmp.x]) continue;
        vis[tmp.x] = true;
        for (auto t : edges[tmp.x]) {
            int v = t.first;
            long long w = t.second;
            if (!vis[v] && dis[v] > w + dis[tmp.x]) {
                dis[v] = dis[tmp.x] + w;
                que.push(node(v, dis[v]));
            }
        }
    }
}
long long disFromS[200001], disFromT[200001];
long long numFromS[200001], numFromT[200001];
bool vis[200001];
void dfs(int u, vector<pair<int, int>> edges[], long long num[], long long dis[]) {
    vis[u] = true;
    for (auto t : edges[u]) {
        int v = t.first;
        int w = t.second;
        if (dis[u] + w == dis[v]) {
            if (!vis[v]) dfs(v, edges, num, dis);
            num[u] += num[v];
        }
    }
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edges[u].push_back(make_pair(v, w));
        rev_edges[v].push_back(make_pair(u, w));
        eds.push_back(edge(u, v, w));
    }
    dijkstra(1, edges, disFromS, n);
    dijkstra(2, rev_edges, disFromT, n);

    for (int i = 1; i <= n; ++i) vis[i] = false;
    numFromS[1] = 1;
    dfs(2, rev_edges, numFromS, disFromT);

    for (int i = 1; i <= n; ++i) vis[i] = false;
    numFromT[2] = 1;
    dfs(1, edges, numFromT, disFromS);
    /*for (int i=1;i<=n;++i) cout<<numFromS[i]<<' ';
    cout<<endl;
    for (int i=1;i<=n;++i) cout<<numFromT[i]<<' ';
    cout<<endl;*/

    for (auto t : eds) {
        int u = t.u; int v = t.v; long long w = t.w;
        if (disFromS[v] + disFromT[u] + w < disFromS[2]) printf("HAPPY\n");
        else if (disFromT[v] + w == disFromT[u] && disFromS[v] + disFromT[u] + w > disFromS[2] && numFromS[u] == numFromS[v] && numFromS[v]*numFromT[v] == numFromS[2]) printf("SAD\n");
        else printf("SOSO\n");
    }
}