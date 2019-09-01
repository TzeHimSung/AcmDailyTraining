// 直接跑6次bellman ford即可

/* Contest nanjing_2019_online
 * Problem H
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

int n, m;
const long long int INF = 1000000000000000LL;

struct edge {
    int u, v;
    long long int w;
};

long long int bellman_ford(int s, int t, vector <vector <int>> &g,  vector <edge> &edges) {
    queue <int> q;
    vector <long long int> dis(n);
    vector <bool> inq(n);
    for (int i = 0; i < n; i++) {
        dis[i] = INF;
    }
    dis[s] = 0;
    inq[s] = true;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inq[u] = false;
        for (auto eid : g[u]) {
            edge &e = edges[eid];
            if (dis[e.u] < INF && dis[e.v] > dis[e.u] + e.w) {
                dis[e.v] = dis[e.u] + e.w;
                if (!inq[e.v]) {
                    q.push(e.v);
                    inq[e.v] = true;
                }
            }
        }
    }
    return dis[t];
}

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        vector <vector <int>> g(n);
        vector <edge> edges(m);
        for (int i = 0; i < m; i++) {
            scanf("%d %d %lld", &edges[i].u, &edges[i].v, &edges[i].w);
            g[edges[i].u].emplace_back(i);
        }
        for (int i = 0; i < 6; i++) {
            int s, t;
            scanf("%d %d", &s, &t);
            long long int nw = -bellman_ford(t, s, g, edges);
            printf("%lld\n", nw);
            edges.emplace_back((edge) {
                s, t, nw
            });
            g[s].emplace_back(m + i);
        }
    }
    return 0;
}
