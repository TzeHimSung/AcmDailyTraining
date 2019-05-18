/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
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
int n, m, c, q, fa[maxn];
map<int, int>mp[maxn];
set<int>own[maxn];

int findFa(int v)
{
    return fa[v] < 0 ? v : fa[v] = findFa(fa[v]);
}

void merge(int u, int v)
{
    if ((u = findFa(u)) == (v = findFa(v))) return;
    if ((int)own[u].size() > (int)own[v].size()) swap(u, v);
    fa[u] = v;
    for (auto i : own[u]) own[v].insert(i);
    own[u].clear();
}

void addedge(int u, int v, int c)
{
    if (mp[u].count(c)) merge(v, mp[u][c]);
    if (mp[v].count(c)) merge(u, mp[v][c]);
    mp[u][c] = v; mp[v][c] = u;
    own[findFa(v)].insert(u);
    own[findFa(u)].insert(v);
}

int main()
{
    memset(fa, -1, sizeof(fa));
    scanf("%d %d %d %d ", &n, &m, &c, &q);
    rep1(i, 1, m)
    {
        int u, v, c; scanf("%d %d %d ", &u, &v, &c);
        u--, v--;
        addedge(u, v, c);
    }
    while (q--)
    {
        char op; int x, y, z;
        op = getchar();
        scanf("%d %d ", &x, &y); x--, y--;
        if (op == '+')
        {
            scanf("%d ", &z);
            addedge(x, y, z);
        }
        else
        {
            int rx = findFa(x);
            if (rx == findFa(y) || own[rx].find(y) != own[rx].end())
                puts("Yes");
            else puts("No");
        }
    }
    return 0;
}