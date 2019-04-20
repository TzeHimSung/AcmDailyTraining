/*

补题 cdq分治+树状数组

*/

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

const int maxn = 1e5 + 10;
// const int maxn = 10;
struct Node
{
    int pos, x, y, num;

    bool operator<(const Node &rhs)const
    {
        return x == rhs.x ? y < rhs.y : x < rhs.x;
    }
};

Node p[maxn], q[maxn];
int a[maxn], c[maxn], n, cnt = 0, ans = 0;
//c是树状数组

void update(int x, int val)
{
    for (; x <= n; x += x & -x)
        c[x] = max(c[x], val);
}

int query(int x)
{
    int ret = 0;
    for (; x; x -= x & -x)
        ret = max(ret, c[x]);
    return ret;
}

void recover(int x)
{
    for (; x <= n; x += x & -x)
        c[x] = 0;
}

bool cmp(const Node &a, const Node &b)
{
    return a.pos < b.pos;
}

void cdqSeparation(int l, int r) //important!
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    cdqSeparation(l, mid); //must separate left block firstly
    sort(p + l, p + mid + 1);
    sort(p + mid + 1, p + r + 1);
    int j = l;
    rep1(i, mid + 1, r)
    {
        for (; j <= mid && p[j].x < p[i].x; ++j)
            update(p[j].y, p[j].num);
        p[i].num = max(p[i].num, query(p[i].y - 1) + 1);
    }
    rep1(i, l, mid) recover(p[i].y);
    sort(p + mid + 1, p + r + 1, cmp);
    cdqSeparation(mid + 1, r);
}

int main()
{
    scanf("%d", &n);
    rep1(i, 1, n) scanf("%d%d", &p[i].x, &p[i].y);
    rep1(i, 1, n) a[i] = p[i].x; //a是去重用的临时数组
    rep1(i, 1, n) p[i].num = 1;
    sot(a, n);
    cnt = unique(a + 1, a + 1 + n) - a - 1; //先对第一维去重, 返回去重后元素个数
    rep1(i, 1, n)
    p[i].x = lower_bound(a + 1, a + cnt + 1, p[i].x) - a;
    rep1(i, 1, n) a[i] = p[i].y;
    sot(a, n);
    cnt = unique(a + 1, a + 1 + n) - a - 1;
    rep1(i, 1, n) p[i].y = lower_bound(a + 1, a + 1 + cnt, p[i].y) - a;
    rep1(i, 1, n) p[i].pos = i;
    cdqSeparation(1, n);
    ans = 0;
    rep1(i, 1, n) ans = max(ans, p[i].num);
    printf("%d\n", ans);
    return 0;
}
