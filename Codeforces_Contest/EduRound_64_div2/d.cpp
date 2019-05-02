#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int maxn = 2e5 + 10;

int n, dp[2][maxn];
vector<pair<int, int>> adj[maxn];
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
    for (pair<int, int> v : adj[u])
    {
        if (v.first == p)
            continue;
        dfs1(v.first, u);
        calc(u, v, 1);
    }
    ans += dp[0][u] + dp[1][u];
    ++dp[0][u];
}

void dfs2(int u, int p, int pp1, int pp2)
{
    ans += pp1 + pp2;
    for (pair<int, int> v : adj[u])
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
    cin >> n;
    for (int i = 1, u, v, c; i < n; i++)
    {
        cin >> u >> v >> c;
        --u; --v;
        adj[u].push_back(pair<int, int>(v, c));
        adj[v].push_back(pair<int, int>(u, c));
    }
    dfs1(0, -1); dfs2(0, -1, 0, 0);
    cout << ans << endl;
    return 0;
}
