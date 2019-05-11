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
/* namespace */
using namespace std;
/* header end */

const int maxn = 6e4 + 1e3, maxm = 2400000;
int n, q, m, tot, a[maxn], t[maxn], T[maxn];
int use[maxn], lson[maxm], rson[maxm], c[maxm], s[maxn];

struct Query
{
    int kind;
    int l, r, k;
} query[10010];

void init_hash(int k)
{
    sort(t, t + k);
    m = unique(t, t + k) - t;
}

int Hash(int x)
{
    return lower_bound(t, t + m, x) - t;
}

int build(int l, int r)
{
    int root = tot++;
    c[root] = 0;
    if (l == r) return root;
    int mid = (l + r) >> 1;
    lson[root] = build(l, mid); rson[root] = build(mid + 1, r);
    return root;
}

int insert(int root, int pos, int val)
{
    int newroot = tot++, tmp = newroot, l = 0, r = m - 1;
    c[newroot] = c[root] + val;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (pos <= mid)
        {
            lson[newroot] = tot++; rson[newroot] = rson[root];
            newroot = lson[newroot]; root = lson[root];
            r = mid;
        }
        else
        {
            rson[newroot] = tot++; lson[newroot] = lson[root];
            newroot = rson[newroot]; root = rson[root];
            l = mid + 1;
        }
        c[newroot] = c[root] + val;
    }
    return tmp;
}

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int pos, int d)
{
    while (x <= n)
    {
        s[x] = insert(s[x], pos, d);
        x += lowbit(x);
    }
}

int sum(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += c[lson[use[x]]];
        x -= lowbit(x);
    }
    return ret;
}

int Query(int left, int right, int k)
{
    int left_root = T[left - 1], right_root = T[right];
    int l = 0, r = m - 1;
    for (int i = left - 1; i; i -= lowbit(i)) use[i] = s[i];
    for (int i = right; i; i -= lowbit(i)) use[i] = s[i];
    while (l < r)
    {
        int mid = (l + r) >> 1;
        int tmp = sum(right) - sum(left - 1) + c[lson[right_root]] - c[lson[left_root]];
        if (tmp >= k)
        {
            r = mid;
            for (int i = left - 1; i; i -= lowbit(i))
                use[i] = lson[use[i]];
            for (int i = right; i; i -= lowbit(i))
                use[i] = lson[use[i]];
            left_root = lson[left_root];
            right_root = lson[right_root];
        }
        else
        {
            l = mid + 1; k -= tmp;
            for (int i = left - 1; i; i -= lowbit(i))
                use[i] = rson[use[i]];
            for (int i = right; i; i -= lowbit(i))
                use[i] = rson[use[i]];
            left_root = rson[left_root];
            right_root = rson[right_root];
        }
    }
    return l;
}

int main()
{
    int Tcase; scanf("%d", &Tcase);
    while (Tcase--)
    {
        scanf("%d%d", &n, &q); tot = m = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            t[m++] = a[i];
        }
        char op[10];
        for (int i = 0; i < q; i++)
        {
            scanf("%s", op);
            if (op[0] == 'Q')
            {
                query[i].kind = 0;
                scanf("%d%d%d", &query[i].l, &query[i].r, &query[i].k);
            }
            else
            {
                query[i].kind = 1;
                scanf("%d%d", &query[i].l, &query[i].r);
                t[m++] = query[i].r;
            }
        }
        init_hash(m);
        T[0] = build(0, m - 1);
        for (int i = 1; i <= n; i++)
            T[i] = insert(T[i - 1], Hash(a[i]), 1);
        for (int i = 1; i <= n; i++) s[i] = T[0];
        for (int i = 0; i < q; i++)
        {
            if (!query[i].kind)
                printf("%d\n", t[Query(query[i].l, query[i].r, query[i].k)]);
            else
            {
                add(query[i].l, Hash(a[query[i].l]), -1);
                add(query[i].l, Hash(query[i].r), 1);
                a[query[i].l] = query[i].r;
            }
        }
    }
    return 0;
}