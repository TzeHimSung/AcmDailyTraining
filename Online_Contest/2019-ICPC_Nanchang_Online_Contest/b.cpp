/* Contest nanchang_2019_online
 * Problem B
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

const long long int INF = 10000000000000L;

struct edge {
    int u, v;
    long long int w;
};

struct node {
    int u;
    long long int d;
    bool operator < (const node &n) const {
        return d > n.d;
    }
};

long long int read(void) {
    char ch;
    do {
        ch = getchar();
    } while (!isdigit(ch));
    long long int ret = 0;
    while (isdigit(ch)) {
        ret *= 10;
        ret += ch - '0';
        ch = getchar();
    }
    return ret;
}

void dijkstra(vector <vector <int>> &graph, vector <edge> &edges, vector <long long int> &dis, int s) {
    priority_queue <node> pq;
    pq.push({s, dis[s] = 0});
    vector <int> vis(graph.size());
    while (!pq.empty()) {
        auto tmp = pq.top();
        pq.pop();
        if (vis[tmp.u]) {
            continue;
        }
        vis[tmp.u] = true;
        for (unsigned int i = 0; i < graph[tmp.u].size(); i++) {
            edge &e = edges[graph[tmp.u][i]];
            if (dis[e.v] > dis[e.u] + e.w) {
                pq.push((node) {
                    e.v, dis[e.v] = dis[e.u] + e.w
                });
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    T = read();
    while (T--) {
        int n = read(), m = read(), s = read(), k = read(), c = read();
        int ptr = 0;
        vector <edge> edges(2 * m + k);
        vector <vector <int>> graph(n + 1);
        auto add_edge = [&] (int u, int v, long long int w) {
            graph[u].emplace_back(ptr);
            edges[ptr++] = ((edge) {
                u, v, w
            });
        };
        for (int i = 0; i < k; i++) {
            int v = read();
            add_edge(0, v, 0);
        }
        for (int i = 0; i < m; i++) {
            int u = read(), v = read();
            long long int w = read();
            add_edge(u, v, w);
            add_edge(v, u, w);
        }

        vector <long long int> dis(n + 1, INF);
        dijkstra(graph, edges, dis, s);
        auto ans_s = *max_element(dis.begin() + 1, dis.end());
        for (int i = 0; i <= n; i++) {
            dis[i] = INF;
        }
        dijkstra(graph, edges, dis, 0);
        auto ans_k = *max_element(dis.begin() + 1, dis.end());

        if (ans_k * c < ans_s) {
            cout << ans_k << endl;
        } else {
            cout << ans_s << endl;
        }
    }
    return 0;
}