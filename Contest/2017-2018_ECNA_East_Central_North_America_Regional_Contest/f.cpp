/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
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
#define int int32_t
#define ll int64_t
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
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e4 + 10;
vector<int>g[maxn];
int bcj[maxn], n;
ll maxv = 0, id = 0, ss = 0, res = 0;

void dfs(int u, int fa)
{
    bcj[u] = 1;
    vector<int>vv;
    int sum = 0;
    rep0(i, 0, g[u].size())
    {
        int v = g[u][i];
        if (v == fa) continue;
        dfs(v, u);
        vv.pb(bcj[v]);
        sum += bcj[v];
        bcj[u] += bcj[v];
    }
    int ff = n - sum;
    vv.pb(ff);
    ll res = 0, ss = 0;
    rep0(i, 0, vv.size())
    {
        res += ss * vv[i];
        ss += vv[i];
    }
    if (res > maxv)
    {
        maxv = res;
        id = u;
    }
}

void dfs2(int u, int fa)
{
    bcj[u] = 1;
    int sum = 0;
    rep0(i, 0, g[u].size())
    {
        int v = g[u][i];
        if (v == fa) continue;
        dfs2(v, u);
        bcj[u] += bcj[v];
    }
}

int main()
{
    cin >> n;
    rep1(i, 1, n)
    {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(0, -1); dfs2(id, -1);
    vector<ll>v; v.clear();
    rep0(i, 0, g[id].size()) v.pb(bcj[g[id][i]]);
    if (v.size() == 1)
    {
        puts("0 0");
        return 0;
    }
    sort(begin(v), end(v));
    v[v.size() - 2] += v[v.size() - 1];
    rep0(i, 0, v.size() - 1)
    {
        res += ss * v[i];
        ss += v[i];
    }
    cout << maxv << " " << res << endl;
    return 0;
}