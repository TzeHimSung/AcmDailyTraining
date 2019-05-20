#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <assert.h>
typedef long long ll;
using namespace std;
typedef pair<int, int>pii;
#define lson (root<<1)
#define rson (root<<1|1)

const int N = 1e5 + 10;

vector<pii>G[N];
int fa[N], top[N], sz[N], dep[N], son[N];
int pos[N], cur;

void dfs1(int u, int f, int d)
{
    fa[u] = f, dep[u] = d, sz[u] = 1;
    son[u] = -1;
    for (auto P : G[u])
    {
        int v = P.first;
        if (v == f) continue;
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
        if (son[u] == -1 || sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs2(int u, int t)
{
    top[u] = t, pos[u] = ++cur;
    if (son[u] != -1)
    {
        dfs2(son[u], t);
    }
    for (auto P : G[u])
    {
        int v = P.first;
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

struct Query
{
    int u, v, w, id;
    Query() {}
    Query(int u, int v, int w, int id): u(u), v(v), w(w), id(id) {}
    bool operator < (const Query &tmp)const
    {
        if (w == tmp.w) return id < tmp.id;
        else return w < tmp.w;
    }
} Q[N << 2];

int val[N << 2];
void update(int root, int l, int r, int p)
{
    if (l == r)
    {
        val[root]++;
        return ;
    }
    int m = (l + r) >> 1;
    if (p <= m) update(lson, l, m, p);
    else update(rson, m + 1, r, p);
    val[root] = val[lson] + val[rson];
}

int query(int root, int l, int r, int a, int b)
{
    if (a > b) return 0;
    if (l == a && r == b) return val[root];
    int m = (l + r) >> 1;
    if (b <= m) return query(lson, l, m, a, b);
    else if (a > m) return query(rson, m + 1, r, a, b);
    else return query(lson, l, m, a, m) + query(rson, m + 1, r, m + 1, b);
}

int n;
int gao(int u, int v)
{
    int ans = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        ans += query(1, 1, n, pos[top[u]], pos[u]);
        u = fa[top[u]];
    }
    if (dep[u] < dep[v]) swap(u, v);
    ans += query(1, 1, n, pos[v] + 1, pos[u]);
    return ans;
}

int o[N];
void solve()
{
    int m;
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back(pii(v, w));
        G[v].push_back(pii(u, w));
        Q[++cnt] = Query(u, v, w, 0);
    }
    dfs1(1, 0, 0);
    dfs2(1, 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        Q[++cnt] = Query(u, v, w, i);
    }
    sort(Q + 1, Q + cnt + 1);
    for (int i = 1; i <= cnt; i++)
    {
        int u = Q[i].u, v = Q[i].v, id = Q[i].id;
        if (id == 0)
        {
            if (u != fa[v]) swap(u, v);
            assert(u == fa[v]);
            //  cout<<pos[v]<<endl;
            update(1, 1, n, pos[v]);
        }
        else
        {
            int ans = gao(u, v);
            o[id] = ans;
            //  cerr<<id<<' '<<ans<<endl;
        }
    }
    for (int i = 1; i <= m; i++) printf("%d\n", o[i]);
}

int main()
{
    solve();

    return 0;
}