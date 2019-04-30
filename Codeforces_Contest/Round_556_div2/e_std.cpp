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

const int maxn = 4e5 + 10;
const int maxm = 1 << 20;
int tn, n, Q;
int rp[maxm], rm[maxm], lp[maxm], lm[maxm], aa[maxm], bb[maxm], ans[maxm];
char str[maxn];

void pushup(int curPos)
{
    aa[curPos] = aa[lson] + max(0, aa[rson] - bb[lson]);
    bb[curPos] = bb[rson] + max(0, bb[lson] - aa[rson]);
    rp[curPos] = max(rp[rson], max(rp[lson] - aa[rson] + bb[rson], rm[lson] + aa[rson] + bb[rson]));
    rm[curPos] = max(rm[rson], rm[lson] + aa[rson] - bb[rson]);
    lp[curPos] = max(lp[lson], max(lp[rson] - bb[lson] + aa[lson], lm[rson] + aa[lson] + bb[lson]));
    lm[curPos] = max(lm[lson], lm[rson] - aa[lson] + bb[lson]);
    ans[curPos] = max(max(ans[lson], ans[rson]), max(rm[lson] + lp[rson], rp[lson] + lm[rson]));
}

void getLeaf(int curPos, char ch)
{
    if (ch == '(')
    {
        aa[curPos] = 0, bb[curPos] = 1;
        rp[curPos] = 0, rm[curPos] = 0;
        lp[curPos] = 0, lm[curPos] = 0;
    }
    else
    {
        aa[curPos] = 1, bb[curPos] = 0;
        rp[curPos] = 0, rm[curPos] = 0;
        lp[curPos] = 0, lm[curPos] = 0;
    }
    ans[curPos] = 0;
}

void update(int pos, char ch, int curL = 0, int curR = tn, int curPos = 1)
{
    if (curL == curR)
    {
        getLeaf(curPos, ch);
        return;
    }
    int mid = (curL + curR) >> 1;
    if (pos <= mid) update(pos, ch, curL, mid, curPos << 1);
    else update(pos, ch, mid + 1, curR, curPos << 1 | 1);
    pushup(curPos);
}

void build(int curL = 0, int curR = tn, int curPos = 1)
{
    if (curL == curR)
    {
        getLeaf(curPos, str[curL]);
        return;
    }
    int mid = (curL + curR) >> 1;
    build(curL, mid, curPos << 1);
    build(mid + 1, curR, curPos << 1 | 1);
    pushup(curPos);
}

int main()
{
    scanf("%d%d", &n, &Q);
    scanf("%s", str + 1);
    tn = n * 2 - 1;
    str[0] = '(', str[tn] = ')';
    build();
    printf("%d\n", ans[1]);
    while (Q--)
    {
        int a, b; scanf("%d%d", &a, &b);
        if (str[a] == str[b])
        {
            printf("%d\n", ans[1]);
            continue;
        }
        update(a, str[b]);
        update(b, str[a]);
        printf("%d\n", ans[1]);
        swap(str[a], str[b]);
    }
    return 0;
}