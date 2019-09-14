/* Contest shenyang_2019_online
 * Problem B
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

int read(void) {
    char ch;
    do {
        ch = getchar();
    } while (!isdigit(ch));
    int ret = 0;
    while (isdigit(ch)) {
        ret *= 10;
        ret += ch - '0';
        ch = getchar();
    }
    return ret;
}

int fa[100001], cnt[100001];

int findSet(int u) {
    return u == fa[u] ? u : fa[u] = findSet(fa[u]);
}

void search(int p, vector <vector <int>> &graph, vector <int> &conn, vector <int> &monster, vector <int> &visit) {
    if (visit[p]) {
        return;
    }
    visit[p] = true;
    if (monster[p]) {
        conn.emplace_back(p);
        return;
    }
    for (auto e : graph[p]) {
        search(e, graph, conn, monster, visit);
    }
}

int main(void) {
    int t = read();
    while (t--) {
        int n = read(), m = read(), k = read();
        vector <int> monster(n + 1), vis(n + 1);
        vector <vector <int>> graph(n + 1);
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }
        for (int i = 1; i <= n; i++) {
            fa[i] = i;
            cnt[i] = 1;
        }
        for (int i = 0; i < k; i++) {
            int x;
            scanf("%d", &x);
            monster[x] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (!monster[i] && !vis[i]) {
                queue <int> q;
                q.push(i);
                int index = findSet(i);
                while (!q.empty()) {
                    int t = q.front();
                    q.pop();
                    if (vis[t]) {
                        continue;
                    }
                    vis[t] = true;
                    int ft = findSet(t);
                    if (ft != index) {
                        fa[ft] = index;
                        cnt[index]++;
                    }
                    for (auto e : graph[t]) {
                        if (!monster[e]) {
                            q.push(e);
                        }
                    }
                }
            }
        }
        vector <int> conn;
        vector <int> visit(n + 1);
        search(1, graph, conn, monster, visit);
        double maxi = 0.0;
        for (auto p : conn) {
            double cur = 0.0;
            for (auto l : graph[p]) {
                int tar = findSet(l);
                if (tar != 1 && !monster[tar]) {
                    cur += (double) cnt[tar] / graph[p].size();
                }
            }
            maxi = max(maxi, cur);
        }
        printf("%.9f\n", maxi + cnt[1]);
    }
    return 0;
}