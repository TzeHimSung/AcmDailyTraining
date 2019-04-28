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

inline int read()
{
    int ret = 0; char c;
    c = getchar();
    while (c < '0' || c > '9') c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}

struct Node
{
    int val = -1;
};

Node segT[maxn << 2];
int n, cnt[maxn];

void build(int *a, int curPos, int curL, int curR)
{
    if (curL == curR)
    {
        segT[curPos].val = a[curL];
        return;
    }
    int mid = (curL + curR) >> 1;
    build(a, lson, curL, mid); build(a, rson, mid + 1, curR);
    segT[curPos].val = segT[lson].val + segT[rson].val;
}

int query(int curPos, int k, int curL, int curR)
{
    if (curL == curR)
    {
        return curL;
    }
    int mid = (curL + curR) >> 1;
    if (k <= segT[lson].val)
        return query(lson, k, curL, mid);
    else
        return query(rson, k - segT[lson].val, mid + 1, curR);
}

int main()
{
    scanf("%d", &n);
    rep1(i, 1, n)
    {
        int x; scanf("%d", &x); cnt[x]++;
    }
    build(cnt, 1, 1, n);
    int q; scanf("%d", &q);
    while (q--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", query(1, k, 1, n));
    }
    return 0;
}