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
/* namespace */
using namespace std;
/* header end */

struct Node
{
    ll sum, cost;
};
const int maxn = 1e6 + 10;
Node segT[maxn * 4];
int n, k, m;
ll ans = 0;
vector<pair<ll, ll> >v[maxn];

void update(ll pos, int curPos, ll num, int curL, int curR)
{
    int lson = curPos * 2, rson = curPos * 2 + 1;
    segT[curPos].sum += num * pos;
    segT[curPos].cost += num;
    if (curL == curR)
        return;
    int mid = curL + (curR - curL) / 2;
    if (pos <= mid) update(pos, lson, num, curL, mid);
    else update(pos, rson, num, mid + 1, curR);
}

ll query(ll curPos, ll remain, int curL, int curR)
{
    int lson = curPos * 2, rson = curPos * 2 + 1;
    if (curL == curR)
        return (ll)(curL * remain);
    int mid = curL + (curR - curL) / 2;
    if (remain > segT[lson].cost)
        return segT[lson].sum + query(rson, remain - segT[lson].cost, mid + 1, curR);
    else
        return query(lson, remain, curL, mid);
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    while (m--)
    {
        int l, r, c, p; scanf("%d%d%d%d", &l, &r, &c, &p);
        v[l].pb(mp(c, p));
        v[r + 1].pb(mp(-c, p));
    }
    rep1(i, 1, n)
    {
        int _size = v[i].size();
        rep0(j, 0, _size)
        update(v[i][j].sec, 1, v[i][j].fir,  1, maxn);
        ans += query(1, min(segT[1].cost, (ll)k), 1, maxn );
    }
    printf("%lld\n", ans);
    return 0;
}