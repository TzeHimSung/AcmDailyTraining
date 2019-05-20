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

const int maxn = 1e6 + 10;
struct Node
{
    int l, r;
    ll ma, tag;
};
Node a[maxn * 4];
ll x[maxn], y[maxn], b[maxn];

void build(int k, int l, int r)
{
    a[k].l = a[k].ma = l, a[k].r = r;
    if (l == r) return;
    int mid = l + (r - l) / 2;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
    a[k].ma = max(a[k * 2].ma, a[k * 2 + 1].ma);
}

void signalPointFix(int k, int x, int y, ll z)
{
    if (x == a[k].l && y == a[k].r)
    {
        a[k].tag += z;
        a[k].ma += z;
        return;
    }
    if (a[k].tag)
    {
        signalPointFix(k * 2, a[k * 2].l, a[k * 2].r, a[k].tag);
        signalPointFix(k * 2 + 1, a[k * 2 + 1].l, a[k * 2 + 1].r, a[k].tag);
        a[k].tag = 0;
    }
    if (y <= a[k * 2].r) signalPointFix(k * 2, x, y, z);
    else if (x >= a[k * 2 + 1].l) signalPointFix(k * 2 + 1, x, y, z);
    else
    {
        signalPointFix(k * 2, x, a[k * 2].r, z);
        signalPointFix(k * 2 + 1, a[k * 2 + 1].l, y, z);
    }
    a[k].ma = max(a[k * 2].ma, a[k * 2 + 1].ma);
}

ll queryMa(int k, int x, int y)
{
    if (x == a[k].l && y == a[k].r)
        return a[k].ma;
    if (a[k].tag)
    {
        signalPointFix(k * 2, a[k * 2].l, a[k * 2].r, a[k].tag);
        signalPointFix(k * 2 + 1, a[k * 2 + 1].l, a[k * 2 + 1].r, a[k].tag);
        a[k].tag = 0;
    }
    if (y <= a[k * 2].r)
        return queryMa(k * 2, x, y);
    if (x >= a[k * 2 + 1].l)
        return queryMa(k * 2 + 1, x, y);
    return max(queryMa(k * 2, x, a[k * 2].r), queryMa(k * 2 + 1, a[k * 2 + 1].l, y));
}

void add(int x, int y)
{
    while (x <= 1000000)
    {
        b[x] += y;
        x += x & (-x);
    }
}

ll askSum(int x)
{
    ll ret = 0;
    while (x)
    {
        ret += b[x];
        x -= x & (-x);
    }
    return ret;
}

int main()
{
    build(1, 1, 1000000);
    int q; cin >> q;
    rep1(i, 1, q)
    {
        string s; cin >> s;
        if (s[0] == '+')
        {
            scanf("%d%d", &x[i], &y[i]);
            signalPointFix(1, 1, x[i], y[i]);
            add(x[i], y[i]);
        }
        else if (s[0] == '-')
        {
            scanf("%d", &x[i]);
            signalPointFix(1, 1, x[x[i]], -y[x[i]]);
            add(x[x[i]], -y[x[i]]);
        }
        else if (s[0] == '?')
        {
            scanf("%d", &x[i]);
            printf("%lld\n", queryMa(1, 1, x[i]) - x[i] - askSum(1000000) + askSum(x[i]));
        }
    }
    return 0;
}