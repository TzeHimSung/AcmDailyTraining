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
// #define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
/* namespace */
using namespace std;
/* header end */

struct Node
{
    ll lson, rson, sum, sign;
    void init()
    {
        sum = sign = 0;
    }
};

const int maxn = 1e6 + 10;
Node segT[maxn << 2];
ll n, m, tot, ans[maxn], num[maxn], le[maxn], ri[maxn];
vector<pair<ll, ll>>leftQ[maxn], rightQ[maxn];

void build(ll curPos, ll curL, ll curR)
{
    if (curL == curR) return;
    ll mid = (curL + curR) >> 1;
    segT[curPos].lson = ++tot;
    build(tot, curL, mid);
    segT[curPos].rson = ++tot;
    build(tot, mid + 1, curR);
}

void add(ll curPos, ll newVal, ll curL, ll curR, ll qL, ll qR)
{
    segT[curPos].sum += (qR - qL + 1) * newVal;
    if (qL == curL && curR == qR)
    {
        segT[curPos].sign += newVal;
        return;
    }
    ll mid = (curL + curR) >> 1;
    if (qL <= mid) add(segT[curPos].lson, newVal, curL, mid, qL, min(mid, qR));
    if (mid < qR) add(segT[curPos].rson, newVal, mid + 1, curR, max(qL, mid + 1), qR);
}

ll ask(ll curPos, ll curL, ll curR, ll qL, ll qR)
{
    if (qL == curL && curR == qR)
        return segT[curPos].sum;
    ll res = (qR - qL + 1) * segT[curPos].sign, mid = (curL + curR) >> 1;
    if (qL <= mid)
        res += ask(segT[curPos].lson, curL, mid, qL, min(qR, mid));
    if (mid < qR)
        res += ask(segT[curPos].rson, mid + 1, curR, max(qL, mid + 1), qR);
    return res;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    rep1(i, 1, n) scanf("%lld", &num[i]);
    rep1(i, 1, m) scanf("%lld", &le[i]);
    rep1(i, 1, m)
    {
        scanf("%lld", &ri[i]);
        leftQ[ri[i]].pb(mp(le[i], i));
        rightQ[le[i]].pb(mp(ri[i], i));
    }
    num[0] = num[n + 1] = ll_inf;
    rep1(i, 1, n)
    {
        le[i] = i - 1;
        for (; num[i] > num[le[i]]; le[i] = le[le[i]]);
    }
    for (int i = n; i >= 1; i--)
    {
        ri[i] = i + 1;
        for (; num[i] > num[ri[i]]; ri[i] = ri[ri[i]]);
    }
    build(tot = 1, 1, n);
    rep1(i,1,n)
    {
        add(1,1,1,n,le[i]+1,i);
        rep0(j,0,(int)leftQ[i].size())
            ans[leftQ[i][j].second]=ask(1,1,n,leftQ[i][j].first,i);
    }
    rep1(i, 1, tot) segT[i].init();
    for (int i = n; i >= 1; i--)
    {
        if (i + 1 < ri[i])
            add(1, 1, 1, n, i + 1, ri[i] - 1);
        rep0(j, 0, (int)rightQ[i].size())
        ans[rightQ[i][j].second] += ask(1, 1, n, i, rightQ[i][j].first);
    }
    rep1(i, 1, m) printf("%lld ", ans[i]);
    puts("");
    return 0;
}