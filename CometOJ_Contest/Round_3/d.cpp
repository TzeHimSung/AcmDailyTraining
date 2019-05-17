/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 5e4 + 10;
int n, m, l[maxn << 2], r[maxn << 2], bit[maxn], a[maxn], mx;
void addbit(int x, int y)
{
    while (x <= n)
    {
        bit[x] ^= y;
        x += x & -x;
    }
}

int sumbit(int x)
{
    int ret = 0;
    while (x)
    {
        ret ^= bit[x];
        x -= x & -x;
    }
    return ret;
}

struct Base
{
    int b[32];
    void ins(int v)
    {
        for (int i = 30; ~i; i--)
            if (v & (1 << i))
            {
                if (!b[i])
                {
                    b[i] = v;
                    return;
                }
                else v ^= b[i];
            }
    }
    int work(int v)
    {
        for (int i = 30; ~i; i--) v = max(v, v ^ b[i]);
        return v;
    }
    void clear()
    {
        memset(b, 0, sizeof(b));
    }
} tree[maxn << 2], e;

Base merge(Base x, Base y)
{
    for (int i = 30; ~i; i--)
        if (x.b[i]) y.ins(x.b[i]);
    return y;
}

void build(int curpos, int curl, int curr)
{
    l[curpos] = curl, r[curpos] = curr;
    if (curl == curr)
    {
        tree[curpos].ins(a[curl]); return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    tree[curpos] = merge(tree[lson], tree[rson]);
}

void modify(int curpos, int x, int p)
{
    if (l[curpos] == r[curpos])
    {
        tree[curpos].clear();
        a[x] ^= p;
        addbit(x, p);
        tree[curpos].ins(a[x]);
        return;
    }
    int mid = l[curpos] + r[curpos] >> 1;
    if (x <= mid) modify(lson, x, p);
    else modify(rson, x, p);
    tree[curpos] = merge(tree[lson], tree[rson]);
}

Base query(int curpos, int curl, int curr)
{
    if (curl > curr) return e;
    if (l[curpos] == curl && r[curpos] == curr) return tree[curpos];
    int mid = l[curpos] + r[curpos] >> 1;
    if (curr <= mid) return query(lson, curl, curr);
    else if (curl > mid) return query(rson, curl, curr);
    else return merge(query(lson, curl, mid), query(rson, mid + 1, curr));
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n; i; i--) a[i] ^= a[i - 1], addbit(i, a[i]);
    build(1, 0, n);
    while (m--)
    {
        int op, l, r, v; scanf("%d%d%d%d", &op, &l, &r, &v);
        if (op == 1)
        {
            modify(1, l, v);
            if (r < n) modify(1, r + 1, v);
        }
        else
        {
            ll ans = max(query(1, l + 1, r).work(v), query(1, l + 1, r).work(v ^ sumbit(l)));
            printf("%lld\n", ans);
        }
    }
    return 0;
}