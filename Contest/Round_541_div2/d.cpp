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
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_int 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

struct Node
{
    int v, nxt;
};
const int maxn = 2e3 + 10;
int n, m, M[maxn][maxn], head[maxn * maxn], tot = 0;
int dfn[maxn], low[maxn], stak[maxn], top = 0, vis[maxn], cnt = 0, js = 0, belong[maxn], re[maxn];
int ans[maxn], ru[maxn];
Node e[maxn * maxn];
vector<int>g[maxn], col[maxn];
queue<int>q;
char s[maxn];

void add(int u, int v)
{
    e[++tot].v = v;
    e[tot].nxt = head[u];
    head[u] = tot;
}

void tarjan(int u)
{
    dfn[u] = low[u] = cnt++;
    vis[u] = 1;
    stak[++top] = u;
    for (auto v : g[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            dfn[u] = min(dfn[u], dfn[v]);
        }
        else if (vis[v])
            dfn[u] = min(dfn[u], low[v]);
    }
    if (low[u] == dfn[u])
    {
        js++;
        while (stak[top] != u)
        {
            vis[stak[top]] = 0;
            col[js].pb(stak[top]);
            belong[stak[top]] = js;
            top--;
        }
        top--;
        belong[u] = js;
        vis[u] = 0;
        col[js].pb(u);
    }
}

int main()
{
    cin >> n >> m;
    rep1(i, 1, n)
    {
        scanf("%s", s + 1);
        rep1(j, 1, m)
        {
            if (s[j] == '>')
            {
                M[j + n][i] = 1;
                M[i][j + n] = -1;
                g[j + n].pb(i);
            }
            else if (s[j] == '<')
            {
                M[i][j + n] = 1;
                M[j + n][i] = -1;
                g[i].pb(j + n);
            }
            else
            {
                g[j + n].pb(i);
                g[i].pb(j + n);
            }
        }
    }
    rep1(i, 1, n + m)
    if (!dfn[i])
        tarjan(i);
    rep1(i, 1, js)
    {
        for (auto p : col[i])
            for (auto q : col[i])
                if (M[p][q])
                {
                    puts("No");
                    return 0;
                }
    }
    rep1(i, 1, n + m)
    rep1(j, 1, n + m)
    if (M[i][j] == 1 && belong[i] != belong[j])
    {
        add(belong[i], belong[j]);
        ru[belong[j]]++;
    }
    rep1(i, 1, js)
    if (!ru[i]) q.push(i), ans[i] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            ans[v] = max(ans[v], ans[u] + 1);
            ru[v]--;
            if (!ru[v]) q.push(v);
        }
    }
    puts("Yes");
    rep1(i, 1, n) cout << ans[belong[i]] << " ";
    puts("");
    rep1(i, 1, m) cout << ans[belong[i + n]] << " ";
    puts("");
    return 0;
}