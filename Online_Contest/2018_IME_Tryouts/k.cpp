#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define ff first
#define ss second

int dis[100010][3];
struct edge {
    int u, v, w;
    edge(int _u = 0, int _v = 0, int _w = 0) {
        u = _u, v = _v, w = _w;
    }
} e[200010];
int head[100010], num = 0, vis[200010];
void addedge() {
    int u, v, w;
    cin >> u >> v >> w;
    e[num] = edge(head[u], v, w);
    head[u] = num++;
    e[num] = edge(head[v], u, w);
    head[v] = num++;
}
struct node {
    int val, v, add;
    node(int _val = 0, int _v = 0, int _add = 0) {
        val = _val, v = _v;
        add = _add;
    }
    bool operator<(const node &b) const {
        return val > b.val;
    }
};
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(dis, 0x3f, sizeof dis);
    memset(head, -1, sizeof head);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        addedge();
    }
    priority_queue<node> q;
    q.push(node{ 0, 1, 0 });
    dis[1][0] = 0;
    while (!q.empty()) {
        node x = q.top();
        q.pop();
        for (int i = head[x.v]; i != -1; i = e[i].u) {
            if ((vis[i] & x.add) == 0 && (vis[i ^ 1] & x.add) == 0) {
                vis[i] |= x.add, vis[i ^ 1] |= x.add;
                for (int j = 0; j < 3; j++) {
                    int tmp = dis[e[i].v][j];
                    tmp = min(tmp, dis[x.v][(j + 2) % 3] + e[i].w);
                    if (e[i].v != n) {
                        tmp = min(tmp, dis[x.v][j] + e[i].w * 3);
                        tmp = min(tmp, dis[x.v][(j + 1) % 3] + e[i].w * 5);
                    }
                    if (e[i].v != n && dis[e[i].v][j] != tmp) {
                        if ((vis[i] & 1) == 0)
                            q.push(node{ dis[e[i].v][0], e[i].v, 1 });
                        if ((vis[i] & 2) == 0)
                            q.push(node{ dis[e[i].v][1], e[i].v, 2 });
                        if ((vis[i] & 4) == 0)
                            q.push(node{ dis[e[i].v][2], e[i].v, 4 });
                    }
                    dis[e[i].v][j] = tmp;
                }
            }
        }
    }
    pair<int, string> ans[10];
    ans[1] = { dis[n][0], "me" };
    ans[2] = { dis[n][1], "Gon" };
    ans[3] = { dis[n][2], "Killua" };
    sort(ans + 1, ans + 1 + 3);
    for (int i = 1; i <= 3; i++)
        cout << ans[i].ss << endl;
}