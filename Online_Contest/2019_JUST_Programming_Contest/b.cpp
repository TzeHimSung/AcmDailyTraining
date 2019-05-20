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
int n, m, q, a[maxn], b[maxn], s[maxn << 2], l[maxn << 2], r[maxn << 2];

void build(int curPos, int curL, int curR)
{
    l[curPos] = curL; r[curPos] = curR;
    if (curL < curR)
    {
        int mid = curL + curR >> 1;
        build(lson, curL, mid); build(rson, mid + 1, curR);
        s[curPos] = max(s[lson], s[rson]);
    }
    else
    {
        s[curPos] = b[curL];
    }
}

int query(int curPos, int curL, int curR)
{
    if (l[curPos] == curL && r[curPos] == curR)
    {
        return s[curPos];
    }
    int mid = l[curPos] + r[curPos] >> 1;
    if (curR <= mid) return query(lson, curL, curR);
    if (curL > mid) return query(rson, curL, curR);
    return max(query(lson, curL, mid), query(rson, mid + 1, curR));
}

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &q);
        rep1(i, 1, m) a[i] = 0, b[i] = -1;
        rep0(i, 0, n)
        {
            int x, y; scanf("%d%d", &x, &y);
            for (int j = x; j <= y; j++) a[j] = 1;
        }
        int ql = 1, qr; a[m + 1] = 1;
        rep1(i, 1, m + 1)
        {
            if (a[i] == 1)
            {
                if (i > ql)
                {
                    qr = i - ql;
                    b[qr] = max(b[qr], i - 1);
                }
                ql = i + 1;
            }
        }
        build(1, 1, m);
        while (q--)
        {
            scanf("%d", &ql);
            qr = query(1, ql, m);
            if (qr == -1) ql = -1;
            else ql = qr - ql + 1;
            printf("%d %d\n", ql, qr);
        }
    }
    return 0;
}