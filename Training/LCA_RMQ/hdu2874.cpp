/*

补题 lca

*/

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

const int maxn = 4e4 + 10;
struct Edge
{
    int to, w, nxt;
};

Edge g[maxn << 1];
int n, m, c, root, num, cnt, head[maxn << 1], depth[maxn << 1], first[maxn << 1], dir[maxn << 1], que[maxn << 1], par[maxn], vis[maxn];
int dp[maxn][20];

void add(int u, int v, int w)
{
    g[num].w = w;
    g[num].to = v;
    g[num].nxt = head[u];
    head[u] = num++;
}

int getFa(int x)
{
    if (par[x] == x) return x;
    else return par[x] = getFa(par[x]);
}

void unite(int x, int y)
{
    x = getFa(x), y = getFa(y);
    if (x == y) return;
    else par[x] = y;
}

void dfs(int u, int dep)
{
    vis[u] = true;
    que[++cnt] = u;
    first[u] = cnt;
    depth[cnt] = dep;
    for (int k = head[u]; k != -1; k = g[k].nxt)
    {
        int v = g[k].to, w = g[k].w;
        if (!vis[v])
        {
            dir[v] = dir[u] + w;
            dfs(v, dep + 1);
            que[++cnt] = u;
            depth[cnt] = dep;
        }
    }
}

void st(int n)
{
    rep1(i, 1, n) dp[i][0] = i;
    for (int j = 1; (1 << j) - 1 <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            int a = dp[i][j - 1], b = dp[i + (1 << (j - 1))][j - 1];
            dp[i][j] = depth[a] < depth[b] ? a : b;
        }
}

int rmq(int l, int r)
{
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    int a = dp[l][k], b = dp[r - (1 << k) + 1][k];
    return depth[a] < depth[b] ? a : b;
}

int lca(int u, int v)
{
    int x = first[u], y = first[v];
    if (x > y) swap(x, y);
    int res = rmq(x, y);
    return que[res];
}

int main()
{
    while (scanf("%d%d%d", &n, &m, &c) != EOF)
    {
        num = cnt = 0;
        init(head, -1); init(vis, 0);
        rep1(i, 0, n) par[i] = i;
        rep0(i, 0, m)
        {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            add(x, y, z); add(y, x, z);
            unite(x, y);
        }
        rep1(i, 1, n)
        if (getFa(i) == i)
        {
            dir[i] = 0;
            dfs(i, 1);
        }
        st(2 * n - 1);
        while (c--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if (getFa(u) == getFa(v))
            {
                int _lca = lca(u, v);
                printf("%d\n", dir[u] + dir[v] - 2 * dir[_lca]);
            }
            else puts("Not connected");
        }
    }
    return 0;
}