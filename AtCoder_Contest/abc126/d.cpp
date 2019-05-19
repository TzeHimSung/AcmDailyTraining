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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
struct Edge
{
    int u, v, w;
} edge[maxn * 2];
int n, cnt, ans[maxn], vis[maxn];
vector<int> g[maxn];

void addedge(int u, int v, int w)
{
    edge[++cnt].u = u;
    edge[cnt].v = v;
    edge[cnt].w = w;
    g[u].push_back(cnt);
}

void bfs()
{
    queue<int> Q;
    Q.push(1);
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < g[x].size(); i++)
        {
            int cur = g[x][i];
            if (!vis[edge[cur].v])
            {
                if (edge[cur].w % 2 == 0)
                    ans[edge[cur].v] = ans[x];
                else
                    ans[edge[cur].v] = 1 - ans[x];
                Q.push(edge[cur].v);
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w); addedge(v, u, w);
    }
    bfs();
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}