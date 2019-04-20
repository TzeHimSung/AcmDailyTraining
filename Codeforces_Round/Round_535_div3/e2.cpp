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

//segment tree template
template<class E, int size>
class SegmentTree
{
public:
    vector<E>val, ma;
    SegmentTree()
    {
        val.resize(size * 2, 0);
        ma.resize(size * 2, 0);
    }

    E getVal(int x, int y, int l = 0, int r = size, int k = 1)
    {
        if (r <= x || y <= l)
            return -1 << 30;
        if (x <= l && r <= y)
            return ma[k];
        return val[k] + max(getVal(x, y, l, (l + r) / 2, k * 2), getVal(x, y, (l + r) / 2, r, k * 2 + 1));
    }

    void update(int x, int y, E v, int l = 0, int r = size, int k = 1)
    {
        if (l >= r) return;
        if (x <= l && r <= y)
        {
            val[k] += v;
            ma[k] += v;
        }
        else if (l < y && x < r)
        {
            update(x, y, v, l, (l + r) / 2, k * 2);
            update(x, y, v, (l + r) / 2, r, k * 2 + 1);
            ma[k] = val[k] + max(ma[k * 2], ma[k * 2 + 1]);
        }
    }
};

const int maxn = 1e5 + 10;
int n, m, a[maxn], l[maxn], r[maxn];
SegmentTree < int, 1 << 20 > pl, mi;
vector<int> add[maxn], del[maxn];

int main()
{
    cin >> n >> m;
    rep0(i, 0, n)
    {
        cin >> a[i];
        pl.update(i, i + 1, a[i]);
        mi.update(i, i + 1, -a[i]);
    }
    rep0(i, 0, m)
    {
        cin >> l[i] >> r[i]; l[i]--;
        pl.update(l[i], r[i], -1);
        mi.update(l[i], r[i], 1);
        add[l[i]].pb(r[i]);
        del[r[i]].pb(l[i]);
    }
    int dif = -1, best = 0;
    rep0(i, 0, n)
    {
        for (auto &a : add[i])
        {
            pl.update(i, a, 1);
            mi.update(i, a, -1);
        }
        for (auto &a : del[i])
        {
            pl.update(a, i, -1);
            mi.update(a, i, 1);
        }
        int x = pl.getVal(0, n) + mi.getVal(0, n);
        if (x > dif)
            dif = x, best = i;
    }
    vector<int>v;
    rep0(i, 0, m)
    if (best < l[i] || r[i] <= best)
        v.pb(i + 1);
    cout << dif << endl << v.size() << endl;
    for (auto V : v) cout << V << " ";
    cout << endl;
    return 0;
}