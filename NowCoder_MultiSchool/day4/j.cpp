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

const int maxn = 1e3 + 10;
int n, m, s, t, k, head[maxn], dis[maxn], tot = 0;
vector<Edge>v[maxn];

struct Edge {
    int to, w, next;
    Edge(int a, int b, int c = 0) {
        to = a, w = b, next = c;
    }
} edge[maxn];

void addEdge(int u, int v, int w) {
    tot++;
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot;
}

int main() {
    for (int i = 1; i < maxn; i++) head[i] = -1;
    scanf("%d%d%d%d%d", &n, &m, &s, &t, &k);
    rep1(i, 1, m) {
        int a, b, l; scanf("%d%d%d", &a, &b, &l);
        v[a].pb(Edge(b, l)); v[b].pb(Edge(a, l));
    }
    return 0;
}