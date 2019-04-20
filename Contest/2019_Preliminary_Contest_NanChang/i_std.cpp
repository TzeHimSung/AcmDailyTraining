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

const int maxn = 5e5 + 10;

struct Node
{
    ll maxx, minn;
};

struct SegT
{
    Node mem[maxn << 2];

    void build(ll *s, int curPos, int curL, int curR)
    {
        if (curL == curR)
        {
            mem[curPos].maxx = mem[curPos].minn = s[curL];
            return;
        }
        int mid = (curL + curR) >> 1;
        build(s, lson, curL, mid);
        build(s, rson, mid + 1, curR);
        mem[curPos].maxx = max(mem[lson].maxx, mem[rson].maxx);
        mem[curPos].minn = min(mem[lson].minn, mem[rson].minn);
    }

    ll queryMax(int curPos, int curL, int curR, int qL, int qR)
    {
        if (qL <= curL && curR <= qR)
            return mem[curPos].maxx;
        int mid = (curL + curR) >> 1;
        if (qR <= mid) return queryMax(lson, curL, mid, qL, qR);
        else if (qL > mid) return queryMax(rson, mid + 1, curR, qL, qR);
        else return max(queryMax(lson, curL, mid, qL, mid), queryMax(rson, mid + 1, curR, mid + 1, qR));
    }

    ll queryMin(int curPos, int curL, int curR, int qL, int qR)
    {
        if (qL <= curL && curR <= qR)
            return mem[curPos].minn;
        int mid = (curL + curR) >> 1;
        if (qR <= mid) return queryMin(lson, curL, mid, qL, qR);
        else if (qL > mid) return queryMin(rson, mid + 1, curR, qL, qR);
        else return min(queryMin(lson, curL, mid, qL, mid), queryMin(rson, mid + 1, curR, mid + 1, qR));
    }
};
SegT segT1, segT2;
int n, a[maxn], l[maxn], r[maxn];
ll ans = -1e18, s1[maxn], s2[maxn];

void solve()
{
    stack<int>st; st.push(1);
    l[1] = 1;
    rep1(i, 2, n)
    {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop();
        if (st.empty()) l[i] = 1;
        else l[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    r[n] = n; st.push(n);
    for (int i = n - 1; i >= 1; i--)
    {
        while (!st.empty() && a[i] < a[st.top()]) st.pop();
        if (st.empty()) r[i] = n;
        else r[i] = st.top() - 1;
        st.push(i);
    }
}

int main()
{
    scanf("%d", &n);
    s1[0] = 0; s2[n + 1] = 0;
    rep1(i, 1, n)
    {
        scanf("%d", &a[i]);
        s1[i] = s1[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) s2[i] = s2[i + 1] + a[i];
    segT1.build(s1, 1, 1, n);
    segT2.build(s2, 1, 1, n);
    solve();
    rep1(i, 1, n)
    {
        ll maxl = segT2.queryMax(1, 1, n, l[i], i) - s2[i + 1];
        ll maxr = segT1.queryMax(1, 1, n, i, r[i]) - s1[i - 1];
        ll tmp = a[i] * (maxl + maxr - a[i]);
        ans = max(ans, tmp);
        maxl = segT2.queryMin(1, 1, n, l[i], i) - s2[i + 1];
        maxr = segT1.queryMin(1, 1, n, i, r[i]) - s1[i - 1];
        tmp = a[i] * (maxl + maxr - a[i]);
        ans = max(ans, tmp);
    }
    printf("%lld\n", ans);
    return 0;
}