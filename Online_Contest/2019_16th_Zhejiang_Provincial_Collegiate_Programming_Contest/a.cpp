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

const int maxn = 1e5 + 10;
ll sum[maxn << 2], sumn[maxn << 2], sume[maxn << 2], nei[maxn << 2], summan[maxn << 2];
int f[maxn], fsz[maxn], n, Q;
ll fed[maxn], sn, sm, tn;

inline ll read()
{
    ll d = 0;
    char s = getchar();
    while (s < '0' || s > '9')
        s = getchar();
    while (s >= '0' && s <= '9')
    {
        d = d * 10 + s - '0';
        s = getchar();
    }
    return d;
}

int findFa(int x)
{
    if (f[x] == x) return x;
    return f[x] = findFa(f[x]);
}

void maintain(int curPos)
{
    sum[curPos] = sum[lson] + sum[rson];
    sumn[curPos] = sumn[lson] + sumn[rson];
    sume[curPos] = sume[lson] + sume[rson];
    nei[curPos] = nei[lson] + nei[rson];
    summan[curPos] = summan[lson] + summan[rson];
}

void build(int curPos, int curL, int curR)
{
    if (curL == curR)
    {
        sumn[curPos] = sum[curPos] = curL == 1 ? n : 0;
        sume[curPos] = nei[curPos] = summan[curPos] = 0;
        return;
    }
    int mid = (curL + curR) >> 1;
    build(lson, curL, mid); build(rson, mid + 1, curR);
    maintain(curPos);
}

void add(int pos, int val, int curPos, int curL, int curR, ll ve)
{
    if (curL == curR)
    {
        sum[curPos] += (ll)curL * val;
        sumn[curPos] += val;
        sume[curPos] += ve;
        nei[curPos] = (ll)curL * (curL - 1) / 2 * sumn[curPos] - sume[curPos];
        summan[curPos] = (ll)curL * (curL - 1) / 2 * sumn[curPos];
        return;
    }
    int mid = (curL + curR) >> 1;
    if (pos <= mid)
        add(pos, val, lson, curL, mid, ve);
    else
        add(pos, val, rson, mid + 1, curR, ve);
    maintain(curPos);
}

void query(int curPos, int l, int r, ll K)
{
    if (l == r)
    {
        int _l = 1, _r = sumn[curPos], ans = K ? 1 : 0;
        while (_l <= _r)
        {
            int mid = (_l + _r) >> 1;
            ll sp = sn + (ll) l * mid;
            ll g = sp * (sp - 1) / 2 - sm - (ll) l * (l - 1) / 2 * mid;
            if (g <= K)
            {
                if (g < K)
                    ans = max(ans, mid + 1);
                else
                    ans = max(ans, mid);
                _l = mid + 1;
            }
            else
                _r = mid - 1;
        }
        tn += ans;
        return;
    }
    int mid = (l + r) >> 1;
    ll sp = sn + sum[rson];
    ll g = sp * (sp - 1) / 2 - summan[rson] - sm;
    if (g == K)
    {
        sn += sum[rson];
        tn += sumn[rson];
    }
    if (g < K)
    {
        sn += sum[rson];
        sm += summan[rson];
        tn += sumn[rson];
        query(lson, l, mid, K);
    }
    if (g > K)
        query(rson, mid + 1, r, K);
}

int main()
{
    int t = read();
    while (t--)
    {
        n = read(), Q = read();
        rep1(i, 1, n)
        {
            f[i] = i, fsz[i] = 1, fed[i] = 0;
        }
        build(1, 1, n);
        int bsz = n;
        while (Q--)
        {
            int op = read();
            if (op == 1)
            {
                int x = read(), y = read();
                int dx = findFa(x), dy = findFa(y);
                if (dx == dy)
                {
                    fed[dx]++;
                    add(fsz[dx], 0, 1, 1, n, 1);
                }
                else
                {
                    add(fsz[dx], -1, 1, 1, n, -fed[dx]);
                    add(fsz[dy], -1, 1, 1, n, -fed[dy]);
                    add(fsz[dx] + fsz[dy], 1, 1, 1, n, fed[dx] + fed[dy] + 1);
                    f[dx] = dy;
                    fsz[dy] += fsz[dx];
                    fed[dy] += fed[dx] + 1;
                    bsz--;
                }
            }
            else
            {
                ll K = read();
                int mi = max(bsz - K, 1LL), ma;
                K -= nei[1];
                if (K <= 0)
                    ma = bsz;
                else
                {
                    sn = sm = tn = 0;
                    query(1, 1, n, K);
                    ma = bsz - tn + 1;
                }
                printf("%d %d\n", mi, ma);
            }
        }
    }
    return 0;
}