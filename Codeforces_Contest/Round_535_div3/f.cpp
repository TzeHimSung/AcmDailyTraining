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

//disjoint set union template
template<int num>
class DisjointSetUnion
{
public:
    vector<int>par, rank, cnt;

    DisjointSetUnion()
    {
        par = rank = vector<int>(num, 0);
        cnt = vector<int>(num, 1);
        rep0(i, 0, num) par[i] = i;
    }

    void reinit()
    {
        rep0(i, 0, num)
        {
            rank[i] = 0; cnt[i] = 1; par[i] = i;
        }
    }

    int operator[](int x)
    {
        return (par[x] == x) ? (x) : (par[x] = operator[](par[x]));
    }

    int count(int x)const
    {
        return cnt[operator[](x)];
    }

    int operator()(int x, int y)
    {
        if ((x = operator[](x)) == (y = operator[](y)))
            return x;
        cnt[y] = cnt[x] = cnt[x] + cnt[y];
        if (rank[x] > rank[y])
            return par[x] = y;
        rank[x] += rank[x] == rank[y];
        return par[y] = x;
    }
};

const int maxn = 5e5 + 10;
map<int, vector<pair<int, int>>>edge;
DisjointSetUnion<maxn> dsu;
int n, m, ans = 0;

int main()
{
    cin >> n >> m;
    rep1(i, 1, m)
    {
        int u, v, w; cin >> u >> v >> w;
        edge[w].pb(mp(u - 1, v - 1));
    }
    for (auto &e : edge)
    {
        vector<pair<int, int>>p;
        for (auto &a : e.sec)
            if (dsu[a.fir] != dsu[a.sec])
                p.pb(a);
        for (auto &a : p)
        {
            if (dsu[a.fir] != dsu[a.sec])
                dsu(a.fir, a.sec);
            else
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}