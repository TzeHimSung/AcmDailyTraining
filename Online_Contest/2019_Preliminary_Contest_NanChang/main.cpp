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
#define init(a,b) fill(begin(a),end(a),b)
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

const int maxn = 5e5 + 10;
struct Node
{
    Node() {}
    int min = INT_MAX;
};
struct Node2
{
    Node2() {}
    ll ans = LONG_LONG_MIN;
    int l, r;
};
Node segT_1[maxn << 2];
Node2 segT_2[maxn << 2];
int n, p = 0;
ll sum[maxn], a[maxn];

void build(int pos, int val, int curPos, int curL, int curR)
{
    if (curL == curR)
    {
        segT_1[curPos].min = val;
        return;
    }
    int mid = (curL + curR) / 2;
    if (pos <= mid) build(pos, val, 2 * curPos, curL, mid);
    else build(pos, val, 2 * curPos + 1, mid + 1, curR);
    segT_1[curPos].min = min(segT_1[lson].min, segT_1[rson].min);
}

ll query(int curPos, int curL, int curR, int qL, int qR)
{
    if (curL == curR) return segT_1[curPos].min;
    if (qL <= curL && curR <= qR) return segT_1[curPos].min;
    int mid = curL + (curR - curL) / 2;
    ll ret = INT_MAX;
    if (qL <= mid) ret = min(ret, query(lson, curL, mid, qL, qR));
    if (mid < qR) ret = min(ret, query(rson, mid + 1, curR, qL, qR));
    return ret;
}

void build2(int curPos, int curL, int curR)
{
    if (curL == curR)
    {
        segT_2[curPos].ans = (ll)a[curL] * a[curL];
        segT_2[curPos].l = curL;
        segT_2[curPos].r = curR;
        return;
    }
    int mid = (curL + curR) >> 1;
    build2(lson, curL, mid);
    build2(rson, mid + 1, curR);
    segT_2[curPos].l = curL; segT_2[curPos].r = curR;
    ll leftone = (sum[segT_2[lson].r] - sum[segT_2[lson].l - 1]) * query(1, 1, n, segT_2[lson].l, segT_2[lson].r);
    ll rightone = (sum[segT_2[rson].r] - sum[segT_2[rson].l - 1]) * query(1, 1, n, segT_2[rson].l, segT_2[rson].r);
    segT_2[curPos].ans = max(leftone, rightone);
    segT_2[curPos].ans = max(tmp, segT_2[curPos].ans);
    segT_2[curPos].ans = max(segT_2[lson].ans, segT_2[curPos].ans);
    segT_2[curPos].ans = max(segT_2[rson].ans, segT_2[curPos].ans);
}

int main()
{
    sum[p] = 0;
    scanf("%d", &n);
    rep1(i, 1, n)
    {
        scanf("%lld", &a[i]); ++p;
        sum[p] = sum[p - 1] + a[i];
        build(i, a[i], 1, 1, n);
    }
    build2(1, 1, n);
    printf("%lld\n", segT_2[1].ans);
    return 0;
}