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

const int maxn = 2e5 + 10;
char s[maxn];

struct Node
{
    int sum, pmx, lmx, minn, maxx, d;
    Node() {}
    Node(int a, int b, int c, int d, int e, int f)
    {
        sum = a; pmx = b; lmx = c; minn = d; maxx = e; d = f;
    }
};

ostream &operator<<(ostream &os, const Node &rhs)
{
    os << rhs.sum << " " << rhs.pmx << " " << rhs.lmx << " " << rhs.minn << " " << rhs.maxx << " " << rhs.d;
    return os;
}

Node segT[maxn << 2];

void maintain(int curPos)
{
    segT[curPos].sum = segT[lson].sum + segT[rson].sum;
    segT[curPos].pmx = max(segT[lson].pmx, max(segT[rson].maxx - 2 * segT[lson].minn + segT[lson].sum, segT[rson].pmx - segT[lson].sum));
    segT[curPos].lmx = max(segT[lson].lmx, max(segT[rson].lmx - segT[lson].sum, segT[lson].maxx - 2 * segT[rson].minn - 2 * segT[lson].sum));
    segT[curPos].minn = min(segT[lson].minn, segT[rson].minn + segT[lson].sum);
    segT[curPos].maxx = max(segT[lson].maxx, segT[rson].maxx + segT[lson].sum);
    segT[curPos].d = max(max(segT[lson].d, segT[rson].d), max(segT[lson].maxx + segT[rson].pmx - segT[lson].sum, segT[lson].lmx + segT[lson].sum + segT[rson].maxx));
}

void build(int curPos, int curL, int curR)
{
    if (curL == curR)
    {
        int x = s[curL] == '(' ? 1 : -1;
        segT[curPos] = Node(x, -x, -x, x, x, 0);
        // cout << segT[curPos] << endl;
        return;
    }
    int mid = curL + curR >> 1;
    build(lson, curL, mid); build(rson, mid + 1, curR);
    maintain(curPos);
}

void update(int pos, int curPos, int curL, int curR)
{
    if (curL == curR)
        return build(curPos, curL, curR);
    int mid = curL + curR >> 1;
    if (pos <= mid)
        update(pos, lson, curL, mid);
    else
        update(pos, rson, mid + 1, curR);
    maintain(curPos);
}

int main()
{
    int n, m; scanf("%d%d", &n, &m);
    scanf("%s", s + 1);
    n = n * 2 - 2;
    build(1, 1, n);
    printf("%d\n", segT[1].d);
    while (m--)
    {
        int x, y; scanf("%d%d", &x, &y);
        swap(s[x], s[y]);
        update(x, 1, 1, n); update(y, 1, 1, n);
        printf("%d\n", segT[1].d);
    }
    return 0;
}