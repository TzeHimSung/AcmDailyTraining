//https://ac.nowcoder.com/acm/contest/200/B?&headNav=www

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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e4 + 10;
struct Node
{
    ll sum, sq, lazyA = 0, lazyQ = 1;
} segt[maxn << 2];

ll n, m, a[maxn];

void build(int curpos, int curl, int curr)
{
    if (curl == curr)
    {
        segt[curpos].sum = a[curl];
        segt[curpos].sq = a[curl] * a[curl];
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    segt[curpos].sum = segt[lson].sum + segt[rson].sum;
    segt[curpos].sq = segt[lson].sq + segt[rson].sq;
}

void pushdown(int curpos, int curl, int curr)
{
    if (segt[curpos].lazyQ != 1)
    {
        segt[lson].lazyQ *= segt[curpos].lazyQ; segt[lson].lazyA *= segt[curpos].lazyQ;
        segt[rson].lazyQ *= segt[curpos].lazyQ; segt[rson].lazyA *= segt[curpos].lazyQ;
        segt[lson].sum *= segt[curpos].lazyQ; segt[lson].sq *= segt[curpos].lazyQ * segt[curpos].lazyQ;
        segt[rson].sum *= segt[curpos].lazyQ; segt[rson].sq *= segt[curpos].lazyQ * segt[curpos].lazyQ;
        segt[curpos].lazyQ = 1;
    }
    if (segt[curpos].lazyA)
    {
        int mid = curl + curr >> 1;
        segt[lson].sq += 2 * segt[curpos].lazyA * segt[lson].sum + segt[curpos].lazyA * segt[curpos].lazyA * (mid - curl + 1);
        segt[lson].sum += segt[curpos].lazyA * (mid - curl + 1);
        segt[rson].sq += 2 * segt[curpos].lazyA * segt[rson].sum + segt[curpos].lazyA * segt[curpos].lazyA * (curr - mid);
        segt[rson].sum += segt[curpos].lazyA * (curr - mid);
        segt[lson].lazyA += segt[curpos].lazyA; segt[rson].lazyA += segt[curpos].lazyA;
        segt[curpos].lazyA = 0;
    }
}

ll querySum(int curpos, int curl, int curr, int ql, int qr)
{
    if (ql <= curl && curr <= qr) return segt[curpos].sum;
    if (segt[curpos].lazyA || segt[curpos].lazyQ != 1) pushdown(curpos, curl, curr);
    int mid = (curl + curr) >> 1;
    ll ret = 0;
    if (ql <= mid) ret += querySum(lson, curl, mid, ql, qr);
    if (qr > mid) ret += querySum(rson, mid + 1, curr, ql, qr);
    return ret;
}

ll querySq(int curpos, int curl, int curr, int ql, int qr)
{
    if (ql <= curl && curr <= qr) return segt[curpos].sq;
    if (segt[curpos].lazyA || segt[curpos].lazyQ != 1) pushdown(curpos, curl, curr);
    int mid = (curl + curr) >> 1;
    ll ret = 0;
    if (ql <= mid) ret += querySq(lson, curl, mid, ql, qr);
    if (qr > mid) ret += querySq(rson, mid + 1, curr, ql, qr);
    return ret;
}

void updateAdd(int curpos, int curl, int curr, int ql, int qr, ll x)
{
    if (ql <= curl && curr <= qr)
    {
        segt[curpos].sq = segt[curpos].sq + x * 2 * segt[curpos].sum + x * x * (curr - curl + 1);
        segt[curpos].sum = segt[curpos].sum + x * (curr - curl + 1);
        segt[curpos].lazyA += x;
        return;
    }
    if (segt[curpos].lazyA || segt[curpos].lazyQ != 1) pushdown(curpos, curl, curr);
    int mid = curl + curr >> 1;
    if (ql <= mid)
        updateAdd(lson, curl, mid, ql, qr, x);
    if (qr > mid)
        updateAdd(rson, mid + 1, curr, ql, qr, x);
    segt[curpos].sum = segt[lson].sum + segt[rson].sum;
    segt[curpos].sq = segt[lson].sq + segt[rson].sq;
}

void updateMul(int curpos, int curl, int curr, int ql, int qr, ll x)
{
    if (ql <= curl && curr <= qr)
    {
        segt[curpos].sq = x * x * segt[curpos].sq;
        segt[curpos].sum = x * segt[curpos].sum;
        segt[curpos].lazyA *= x; segt[curpos].lazyQ *= x;
        return;
    }
    if (segt[curpos].lazyA || segt[curpos].lazyQ != 1) pushdown(curpos, curl, curr);
    int mid = curl + curr >> 1;
    if (ql <= mid)
        updateMul(lson, curl, mid, ql, qr, x);
    if (qr > mid)
        updateMul(rson, mid + 1, curr, ql, qr, x);
    segt[curpos].sum = segt[lson].sum + segt[rson].sum;
    segt[curpos].sq = segt[lson].sq + segt[rson].sq;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    rep1(i, 1, n) scanf("%lld", &a[i]);
    build(1, 1, n);
    while (m--)
    {
        int op; scanf("%d", &op);
        if (op == 1)
        {
            int l, r; scanf("%d%d", &l, &r);
            printf("%lld\n", querySum(1, 1, n, l, r));
        }
        else if (op == 2)
        {
            int l, r; scanf("%d%d", &l, &r);
            printf("%lld\n", querySq(1, 1, n, l, r));
        }
        else if (op == 3)
        {
            int l, r; ll x; scanf("%d%d%lld", &l, &r, &x);
            updateMul(1, 1, n, l, r, x);
        }
        else
        {
            int l, r; ll x; scanf("%d%d%lld", &l, &r, &x);
            updateAdd(1, 1, n, l, r, x);
        }
    }
    return 0;
}