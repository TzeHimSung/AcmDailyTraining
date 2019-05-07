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
const int mod = 1e9 + 7;

struct Matrix
{
    ll data[2][2];
    Matrix()
    {
        data[0][0] = data[0][1] = data[1][0] = data[1][1] = 0;
    }
    //变为转移矩阵
    inline void tran()
    {
        data[0][1] = data[1][0] = data[1][1] = 1, data[0][0] = 0;
    }
    //初始化为对角矩阵
    inline void init()
    {
        *this = Matrix();
        rep1(i, 0, 1) data[i][i] = 1;
    }
    //返回矩阵第x行
    inline ll *operator[](int x)
    {
        return data[x];
    }
    //定义矩阵乘法
    inline void operator*=(Matrix &rhs)
    {
        Matrix qAns;
        rep1(k, 0, 1)
        {
            rep1(i, 0, 1)
            {
                rep1(j, 0, 1)
                qAns[j][i] = (qAns[j][i] + data[j][k] * rhs[k][i]) % mod;
            }
        }
        *this = qAns;
    }
    //矩阵快速幂
    inline void operator^=(int x)
    {
        Matrix base = *this, qAns;
        rep1(i, 0, 1) qAns[i][i] = 1;
        for (register int i = x; i; i >>= 1, base *= base)
            if (i & 1) qAns *= base;
        *this = qAns;
    }
    inline void operator+=(Matrix &rhs)
    {
        rep1(i, 0, 1)
        {
            rep1(j, 0, 1)
            {
                data[i][j] = (data[i][j] + rhs[i][j]) % mod;
            }
        }
    }
    //输出
    inline void pr()
    {
        rep1(t, 0, 1)
        {
            rep1(i, 0, 1) printf("%d ", data[t][i]);
            puts("");
        }
    }
} seg[maxn << 2], add[maxn << 2];

int n, m;
Matrix qAns, markdown;
bool lazyTag[maxn << 2];

inline void pushdown(int curPos)
{
    if (!lazyTag[curPos]) return;
    seg[lson] *= add[curPos]; seg[rson] *= add[curPos];
    add[lson] *= add[curPos]; add[rson] *= add[curPos];
    lazyTag[lson] = lazyTag[rson] = 1;
    add[curPos].init(); lazyTag[curPos] = 0;
}

void build(int curPos, int curL, int curR)
{
    if (curL == curR)
    {
        seg[curPos].tran();
        add[curPos].init();
        int tmp; scanf("%d", &tmp);
        seg[curPos] ^= tmp - 1;
        return;
    }
    int mid = (curL + curR) >> 1;
    add[curPos].init();
    build(lson, curL, mid); build(rson, mid + 1, curR);
    seg[curPos] = Matrix();
    seg[curPos] += seg[lson]; seg[curPos] += seg[rson];
}

void update(int curPos, int curL, int curR, int qL, int qR)
{
    if (qL <= curL && curR <= qR)
    {
        add[curPos] *= markdown; seg[curPos] *= markdown; lazyTag[curPos] = 1;
        return;
    }
    int mid = (curL + curR) >> 1;
    pushdown(curPos);
    if (qL <= mid) update(lson, curL, mid, qL, qR);
    if (mid < qR) update(rson, mid + 1, curR, qL, qR);
    seg[curPos] = Matrix();
    seg[curPos] += seg[lson]; seg[curPos] += seg[rson];
}

void query(int curPos, int curL, int curR, int qL, int qR)
{
    if (qL <= curL && curR <= qR)
    {
        qAns += seg[curPos];
        return;
    }
    int mid = (curL + curR) >> 1;
    pushdown(curPos);
    if (qL <= mid) query(lson, curL, mid, qL, qR);
    if (mid < qR) query(rson, mid + 1, curR, qL, qR);
    seg[curPos] = Matrix();
    seg[curPos] += seg[lson]; seg[curPos] += seg[rson];
}

int main()
{
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    rep1(cnt, 1, m)
    {
        int op; scanf("%d", &op);
        if (op == 1)
        {
            int x, y, t; scanf("%d%d%d", &x, &y, &t);
            markdown.tran(); markdown ^= t;
            update(1, 1, n, x, y);
        }
        else
        {
            int x, y; scanf("%d%d", &x, &y);
            qAns = Matrix();
            query(1, 1, n, x, y);
            printf("%lld\n", (qAns[0][0] + qAns[0][1]) % mod);
        }
    }
    return 0;
}