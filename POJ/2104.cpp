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
int n, m, cnt = 0, root[maxn], a[maxn];

struct Node
{
    int l, r, sum;
};

Node segT[maxn * 25];
vector<int>v;

void update(int curL, int curR, int &x, int y, int pos)
{
    segT[++cnt] = segT[y], segT[cnt].sum++, x = cnt;
    if (curL == curR) return;
    int mid = (curL + curR) >> 1;
    if (pos <= mid) update(curL, mid, segT[x].l, segT[y].l, pos);
    else update(mid + 1, curR, segT[x].r, segT[y].r, pos);
}

int query(int curL, int curR, int x, int y, int k)
{

}

int main()
{
    scanf("%d%d", &n, &m);
    rep1(i, 1, n)
    {
        scanf("%d", &a[i]);
        v.pb(a[i]);
    }
    sort(v.begin(), v.end());
    rep1(i, 1, n)

    return 0;
}