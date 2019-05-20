/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <float.h>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
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
struct Node
{
    int l, r, sum;
};

Node segt[maxn * 25];
vector<int>v;
int n, m, cnt, root[maxn], a[maxn];

int getid(int x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void update(int curl, int curr, int &x, int y, int pos)
{
    segt[++cnt] = segt[y], segt[cnt].sum++, x = cnt;
    if (curl == curr) return;
    int mid = (curl + curr) >> 1;
    if (mid >= pos) update(curl, mid, segt[x].l, segt[y].l, pos);
    else update(mid + 1, curr, segt[x].r, segt[y].r, pos);
}

int query(int curl, int curr, int x, int y, int k)
{
    if (curl == curr) return curl;
    int mid = (curl + curr) >> 1, sum = segt[segt[y].l].sum - segt[segt[x].l].sum;
    if (sum >= k) return query(curl, mid, segt[x].l, segt[y].l, k);
    else return query(mid + 1, curr, segt[x].r, segt[y].r, k - sum);
}

int main()
{
    scanf("%d%d", &n, &m);
    rep1(i, 1, n)
    {
        scanf("%d", &a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    rep1(i, 1, n)
    {
        update(1, n, root[i], root[i - 1], getid(a[i]));
    }
    rep1(i, 1, m)
    {
        int x, y, k; scanf("%d%d%d", &x, &y, &k);
        printf("%d\n", v[query(1, n, root[x - 1], root[y], k) - 1]);
    }
    return 0;
}