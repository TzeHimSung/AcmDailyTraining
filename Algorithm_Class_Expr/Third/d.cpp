// dinic板子, 网络流24题测过
// author: 成子谦
// date: 01/11/2019

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

using namespace std;

const int maxn = 1001;
struct Edge {
    int to, next, flow;
} edge[maxn * maxn];
int if_z, cnt = 1, n, m, s = 0, t = maxn - 1, dis_n[maxn];
int dis_m[maxn], ans, depth[maxn], head[maxn];
bool useable[maxn][maxn];


void addEdge(int u, int v, int w) {
    edge[++cnt].to = v, edge[cnt].next = head[u], head[u] = cnt, edge[cnt].flow = w;
    edge[++cnt].to = u, edge[cnt].next = head[v], head[v] = cnt, edge[cnt].flow = 0;
}

// dinic
bool bfs() {
    queue<int>que; que.push(s);
    memset(depth, -1, sizeof(depth)), depth[s] = 0;
    while (!que.empty()) {
        int pos = que.front(); que.pop();
        for (int i = head[pos]; i; i = edge[i].next) {
            if (depth[edge[i].to] < 0 && edge[i].flow > 0) {
                depth[edge[i].to] = depth[pos] + 1;
                if (edge[i].to == t) return true;
                que.push(edge[i].to);
            }
        }
    }
    return false;
}

int dfs(int now, int flow) {
    if (now == t || flow == 0) return flow;
    int oldflow = 0;
    for (int i = head[now]; i; i = edge[i].next) {
        if (depth[edge[i].to] != depth[now] + 1 || edge[i].flow == 0) continue;
        int pos = dfs(edge[i].to, min(flow, edge[i].flow));
        flow -= pos;
        oldflow += pos;
        edge[i].flow -= pos;
        edge[i ^ 1].flow += pos;
        if (flow == 0) return oldflow;
    }
    return oldflow;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dis_n[i]);
        addEdge(s, i, dis_n[i]);
        ans += dis_n[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d", &dis_m[i]);
        addEdge(i + n, t, dis_m[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            addEdge(i, j + n, 1);
    }
    // dinic
    while (bfs()) {
        ans -= dfs(s, 0x7ffffff);
    }
    if (ans) printf("0\n");
    else {
        for (int i = 1; i <= n; i++) {
            for (int j = head[i]; j; j = edge[j].next) {
                if (edge[j].flow == 0) useable[i][edge[j].to - n] = true;
            }
        }
        printf("1\n");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (useable[i][j]) {
                    if (j < m) printf("%d ", j);
                    else printf("%d", j);
                }
            }
            printf("\n");
        }
    }
    return 0;
}