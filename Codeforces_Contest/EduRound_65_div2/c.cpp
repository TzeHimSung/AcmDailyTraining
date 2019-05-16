/* basic header */
#include <bits/stdc++.h>
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

struct DSU: vector<int>
{
    vector<int>size;
    DSU(int n): vector<int>(n), size(n, 1)
    {
        rep0(i, 0, n) at(i) = i;
    }
    int find(int u)
    {
        return at(u) == u ? u : at(u) = find(at(u));
    }
    void merge(int u, int v)
    {
        u = find(u), v = find(v);
        if (u != v)
        {
            at(v) = u;
            size[u] += size[v];
        }
    }
};

int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    DSU dsu(n + 1);
    rep1(i, 1, m)
    {
        int sum; scanf("%d", &sum);
        if (sum)
        {
            int u; scanf("%d", &u);
            rep0(j, 1, sum)
            {
                int v; scanf("%d", &v); dsu.merge(u, v);
            }
        }
    }
    rep1(i, 1, n) printf("%d ", dsu.size[dsu.find(i)]);
    puts("");
    return 0;
}