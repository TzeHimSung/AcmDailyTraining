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

int n, dp[2][maxn];
vector<pair<int, int>> graph[maxn];
ll ans;

void calc(int u, pair<int, int> v, int mt)
{
    if (!v.second)
        dp[0][u] += mt * dp[0][v.first];
    else
        dp[1][u] += mt * dp[0][v.first] + mt * dp[1][v.first];
}

void dfs1(int u, int p)
{
    for (pair<int, int> v : graph[u])
    {
        if (v.first == p)
            continue;
        dfs1(v.first, u);
        calc(u, v, 1);
    }
    ans += dp[0][u] + dp[1][u];
    dp[0][u]++;
}

void dfs2(int u, int p, int pp1, int pp2)
{
    ans += pp1 + pp2;
    for (pair<int, int> v : graph[u])
    {
        if (v.first == p)
            continue;
        calc(u, v, -1);
        if (!v.second)
            dfs2(v.first, u, pp1 + dp[0][u], 0);
        else
            dfs2(v.first, u, 0, pp1 + pp2 + dp[0][u] + dp[1][u]);
        calc(u, v, 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v, c; i < n; i++)
    {
        scanf("%d%d%d", &u, &v, &c); --u; --v;
        graph[u].pb(mp(v, c));
        graph[v].pb(mp(u, c));
    }
    dfs1(0, -1); dfs2(0, -1, 0, 0);
    cout << ans << endl;
    return 0;
}
