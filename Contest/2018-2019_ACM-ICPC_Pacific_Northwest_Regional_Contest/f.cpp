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
int n, cntx[maxn], cnty[maxn], cnt1 = 0, cnt2 = 0;
ll ans = 0;
vector<pair<int, int>>v[maxn];

//muban

struct Rectangle
{
    int x[2], y[2];
    void read()
    {
        rep0(i, 0, 2) scanf("%d%d", &x[i], &y[i]);
        if (x[0] > x[1]) swap(x[0], x[1]);
        if (y[0] > y[1]) swap(y[0], y[1]);
        cntx[++cnt1] = x[0], cntx[++cnt1] = x[1], cnty[++cnt2] = y[0], cnty[++cnt2] = y[1];
    }
};

struct Node
{
    ll sum, val, lazy;
    Node() {}
    Node(ll a, ll b, ll c): sum(a), val(b), lazy(c) {}
    //maintain
    Node operator+(const Node &rhs)
    {
        return Node(sum + rhs.sum, val + rhs.val, 0);
    }

    void solve()
    {
        val = sum - val; lazy ^= 1;
    }
};

Node segt[maxn << 2];
Rectangle r[maxn];

void _hash()
{
    sot(cntx, cnt1); sot(cnty, cnt2);
    cnt1 = unique(cntx + 1, cntx + 1 + cnt1) - cntx - 1, cnt2 = unique(cnty + 1, cnty + 1 + cnt2) - cnty - 1;
    rep1(i, 1, n)
    {
        rep0(j, 0, 2)
        {
            r[i].x[j] = lower_bound(cntx + 1, cntx + 1 + cnt1, r[i].x[j]) - cntx;
            r[i].y[j] = lower_bound(cnty + 1, cnty + 1 + cnt2, r[i].y[j]) - cnty;
        }
    }
}

void build(int curPos, int curL, int curR)
{
    segt[curPos] = Node(0, 0, 0);
    if (curL == curR)
    {
        segt[curPos].sum = cnty[curL + 1] - cnty[curL];
        return;
    }
    int mid = (curL + curR) >> 1;
    build(lson, curL, mid); build(rson, mid + 1, curR);
    segt[curPos] = segt[lson] + segt[rson];
}

void pushdown(int curPos)
{
    if (!segt[curPos].lazy) return;
    segt[lson].solve(); segt[rson].solve(); segt[curPos].lazy = 0;
}

void update(int curPos, int curL, int curR, int qL, int qR)
{
    if (qL <= curL && curR <= qR)
    {
        segt[curPos].solve(); return;
    }
    int mid = (curL + curR) >> 1;
    pushdown(curPos);
    if (qL <= mid) update(lson, curL, mid, qL, qR);
    if (qR > mid) update(rson, mid + 1, curR, qL, qR);
    segt[curPos] = segt[lson] + segt[rson];
}

int main()
{
    scanf("%d", &n);
    rep1(i, 1, 2 * n) v[i].clear();
    rep1(i, 1, n) r[i].read();
    _hash();
    rep1(i, 1, n)
    {
        v[r[i].x[0]].pb(r[i].y[0], r[i].y[1] - 1);
        v[r[i].x[1]].pb(r[i].y[0], r[i].y[1] - 1);
    }
    n *= 2;
    build(1, 1, n);
    rep0(i, 1, cnt1)
    {
        for (auto i : v[i]) update(1, 1, n, i.first, i.second);
        ans += segt[1].val * (cntx[i + 1] - cntx[i]);
    }
    printf("%lld\n", ans);
    return 0;
}