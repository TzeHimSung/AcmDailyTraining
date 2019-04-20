#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <stack>
#include <assert.h>
typedef long long ll;
using namespace std;

const int N = 5e5 + 10;
int a[N];
int l[N], r[N];
int n;

void gao()
{
    stack<int>st;
    st.push(1);
    l[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        while (!st.empty() && a[i] <= a[st.top()]) st.pop();
        if (st.empty()) l[i] = 1;
        else l[i] = st.top() + 1;
        st.push(i);
    }
    while (!st.empty()) st.pop();
    r[n] = n;
    st.push(n);
    for (int i = n - 1; i >= 1; i--)
    {
        while (!st.empty() && a[i] < a[st.top()]) st.pop();
        if (st.empty()) r[i] = n;
        else r[i] = st.top() - 1;
        st.push(i);
    }
}

#define lson (root<<1)
#define rson (root<<1|1)

struct Tree
{
    ll ma[N << 2], mi[N << 2];
    void build(ll *s, int root, int l, int r)
    {
        if (l == r)
        {
            ma[root] = mi[root] = s[l];
            return ;
        }
        int m = (l + r) >> 1;
        build(s, lson, l, m);
        build(s, rson, m + 1, r);
        ma[root] = max(ma[lson], ma[rson]);
        mi[root] = min(mi[lson], mi[rson]);
    }
    ll query_max(int root, int l, int r, int a, int b)
    {
        if (l == a && r == b) return ma[root];
        int m = (l + r) >> 1;
        if (b <= m) return query_max(lson, l, m, a, b);
        else if (a > m) return query_max(rson, m + 1, r, a, b);
        else return max(query_max(lson, l, m, a, m), query_max(rson, m + 1, r, m + 1, b));
    }
    ll query_min(int root, int l, int r, int a, int b)
    {
        if (l == a && r == b) return mi[root];
        int m = (l + r) >> 1;
        if (b <= m) return query_min(lson, l, m, a, b);
        else if (a > m) return query_min(rson, m + 1, r, a, b);
        else return min(query_min(lson, l, m, a, m), query_min(rson, m + 1, r, m + 1, b));
    }
} t[2];

ll s[2][N];
void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    //前缀后缀和
    for (int i = 1; i <= n; i++) s[0][i] = s[0][i - 1] + a[i];
    for (int i = n; i >= 1; i--) s[1][i] = s[1][i + 1] + a[i];
    t[0].build(s[0], 1, 1, n);
    t[1].build(s[1], 1, 1, n);
    gao();
    ll ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        ll ml = t[1].query_max(1, 1, n, l[i], i) - s[1][i + 1];
        ll mr = t[0].query_max(1, 1, n, i, r[i]) - s[0][i - 1];
        ll tmp = (ml + mr - a[i]) * a[i];
        ans = max(ans, tmp);
        ml = t[1].query_min(1, 1, n, l[i], i) - s[1][i + 1];
        mr = t[0].query_min(1, 1, n, i, r[i]) - s[0][i - 1];
        tmp = (ml + mr - a[i]) * a[i];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}