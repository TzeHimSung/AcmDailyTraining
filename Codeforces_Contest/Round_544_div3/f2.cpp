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
#include <unordered_set>
#include <bitset>
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
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
vector<int>g[maxn];
vector<pair<int, int>>v;
unordered_set<int>must;
bitset<maxn>vis;
int n, m, d, deg[maxn];

void dfs(int curr)
{
    vis[curr] = 1;
    for (auto i : g[curr])
        if (!vis[i])
        {
            if (curr == 1) must.insert(i);
            dfs(i);
        }
}

void bfs(int curr)
{
    queue<int>q;
    while (!q.empty()) q.pop();
    q.push(curr);
    vis[curr] = 1;
    while (!q.empty())
    {
        curr = q.front(); q.pop();
        for (auto i : g[curr])
            if (!vis[i])
            {
                v.pb(mp(curr, i));
                q.push(i);
                vis[i] = 1;
                if (curr == 1) d--;
                if (curr == 1 && !d) break;
            }
    }
}

int main()
{
    cin >> n >> m >> d;
    rep1(i, 1, m)
    {
        int x, y; cin >> x >> y;
        deg[x]++, deg[y]++;
        g[x].pb(y); g[y].pb(x);
    }
    dfs(1);
    vis.reset();
    vector<int>nv;
    for (auto i : g[1])
        if (must.find(i) != must.end())
            nv.pb(i);
    for (auto i : g[1])
        if (must.find(i) == must.end())
            nv.pb(i);
    g[1] = nv;
    bfs(1);
    if (d || (int)v.size() != n - 1)
        return cout << "NO", 0;
    else
    {
        puts("YES");
        for (auto i : v) cout << i.first << " " << i.second << endl;
    }
    return 0;
}