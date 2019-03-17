/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <climits>
#include <float.h>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
struct Node
{
    int v, w, nxt;
};

Node g[maxn];
int n, m, cnt, head[maxn], dep[maxn], f[maxn][30], dis[maxn];

void addEdge(int u, int v, int w)
{
    g[++cnt].nxt = head[u];
    head[u] = cnt;
    g[cnt].v = v;
    g[cnt].w = w;
}

void dfs(int u, int fa, int depth)
{
    f[u][0] = fa;
    dep[u] = depth;
    rep0(i, 1, 23)
    f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = head[u]; i != -1; i = g[i].nxt)
    {
        int v = g[i].v;
        if (fa == v) continue;
        dis[v] = dis[u] + g[i].w;
        dfs(v, u, depth + 1);
    }
}

int lca(int x, int y)
{
    if (dep[x] < dep[y]) swap(x, y);
    for (int i = 22; i >= 0; i--)
        if (dep[f[x][i]] >= dep[y]) x = f[x][i];
    if (x == y) return x;
    for (int i = 22; i >= 0; i--)
        if (f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    return f[x][0];
}

int calc(int x, int y)
{
    return dis[x] + dis[y] - 2 * dis[lca(x, y)];
}

int main()
{
    int flag = 0;
    while (scanf("%d", &n) != EOF)
    {
        if (flag) puts("");
        flag = 1;
        init(head, -1); cnt = -1;
        init(dis, 0); init(dep, 0);
        memset(f, 0, sizeof(f));
        rep0(i, 1, n)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            addEdge(x, y, z); addEdge(y, x, z);
        }
        dfs(0, 0, 0);
        scanf("%d", &m);
        rep0(i, 0, m)
        {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            int ans = calc(x, y) + calc(y, z) + calc(x, z);
            printf("%d\n", ans / 2);
        }
    }
    return 0;
}