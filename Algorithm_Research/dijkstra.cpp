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

struct Edge {
    int to, w;
    Edge() {}
    Edge(int _to, int _w): to(_to), w(_w) {}
};

struct Point {
    int index;
    ll w;
    Point() {}
    Point(int _index, ll _w): index(_index), w(_w) {}
    bool operator<(const Point &rhs)const {
        return w > rhs.w;
    }
};

const int maxn = 1e5 + 10;
const ll INF = 0x3f3f3f3f;
int n, m, s, t, vis[maxn];
ll dis[maxn];
vector<Edge>g[maxn];

void dijkstra() {
    // init
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
        dis[i] = INF;
    }
    dis[s] = 0;
    priority_queue<Point>q;
    while (!q.empty()) q.pop();
    q.push(Point(s, 0));

    while (!q.empty()) {
        int currPoint = q.top().index;
        q.pop();
        if (vis[currPoint]) continue;
        vis[currPoint] = 1;
        for (auto e : g[currPoint]) {
            dis[e.to] = min(dis[e.to], dis[currPoint] + e.w);
            if (!vis[e.to]) q.push(Point(e.to, dis[e.to]));
        }
    }
}

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x].emplace_back(Edge(y, z));
        g[y].emplace_back(Edge(x, z));
    }
    dijkstra();
    printf("%lld\n", dis[t]);
    return 0;
}