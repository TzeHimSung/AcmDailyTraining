/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e3 + 10, maxm = 5e4 + 10;
int n, m, tot = 1, head[maxn], vis[maxn], cnt[maxn][maxn];
vector<pair<int, int>>e, ans;
struct Edge {
    int to, next;
} edge[maxm];

void add(int from, int to) {
    edge[++tot].to = to;
    edge[tot].next = head[from];
    head[from] = tot;
}

bool bfs(int s, int t) {
    for (int i = 0; i < maxn; i++) vis[i] = 0;
    vis[s] = 1;
    queue<int>q;
    while (!q.empty()) q.pop();
    q.push(s);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int i = head[curr]; i; i = edge[i].next) {
            int to = edge[i].to;
            if ((curr == s && to == t) || vis[to]) continue;
            q.push(to); vis[to] = 1;
            if (to == t) return false;
        }
    }
    return vis[t] ? false : true;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        add(x, y); e.pb(mp(x, y)); cnt[x][y]++;
    }
    for (auto i : e) {
        if (cnt[i.first][i.second] > 1) continue;
        if (bfs(i.first, i.second)) ans.pb(i);
    }
    printf("%d\n", (int)ans.size());
    for (auto i : ans) printf("%d %d\n", i.first, i.second);
    return 0;
}