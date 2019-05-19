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

struct Query
{
    int v, t, m, id;
    Query() {}
    Query(int a, int b, int c, int d): v(a), t(b), m(c), id(d) {}
    Query(int a, int b, int c): v(a), t(b), id(c) {}
    bool operator<(const Query &rhs)const
    {
        return t < rhs.t;
    }
};
int q;
vector<Query>query;

int main()
{
    query.clear();
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int op; scanf("%d", &op);
        if (op == 1)
        {
            int v, t, m; scanf("%d%d%d", &v, &t, &m);
            query.pb(Query(v, t, m, i));
        }
        else
        {
            int v, t; scanf("%d%d", &v, &t);
            query.pb(Query(v, t, i));
        }
    }
    for (auto it : query)
    {

    }
    return 0;
}