// //分块
// #include <bits/stdc++.h>
// /* define */
// #define ll long long
// #define dou double
// #define pb emplace_back
// #define mp make_pair
// #define fir first
// #define sec second
// #define sot(a,b) sort(a+1,a+1+b)
// #define rep1(i,a,b) for(int i=a;i<=b;++i)
// #define rep0(i,a,b) for(int i=a;i<b;++i)
// #define repa(i,a) for(auto &i:a)
// #define eps 1e-8
// #define int_inf 0x3f3f3f3f
// #define ll_inf 0x7f7f7f7f7f7f7f7f
// #define lson curPos<<1
// #define rson curPos<<1|1
// /* namespace */
// using namespace std;
// /* header end */

// const int maxn = 5e4 + 10;
// int n, m, unit, num[maxn], a[maxn];
// struct Interval
// {
//     int l, r, id;
//     bool operator<(const Interval &rhs)const
//     {
//         if (l / unit != rhs.l / unit) return l / unit < rhs.l / unit;
//         else return r < rhs.r;
//     }
// } interval[maxn];
// struct Ans
// {
//     ll a, b;
//     void reduce()
//     {
//         ll g = __gcd(a, b);
//         a /= g, b /= g;
//     }
// } ans[maxn];

// void solve()
// {
//     ll tmp = 0;
//     rep0(i, 0, maxn) num[i] = 0;
//     int l = 1, r = 0; //初始区间
//     rep1(i, 1, m)
//     {
//         while (r < interval[i].r)
//         {
//             r++;
//             tmp -= (ll)num[a[r]] * num[a[r]];
//             num[a[r]]++;
//             tmp += (ll)num[a[r]] * num[a[r]];
//         }
//         while (r > interval[i].r)
//         {
//             tmp -= (ll)num[a[r]] * num[a[r]];
//             num[a[r]]--;
//             tmp += (ll)num[a[r]] * num[a[r]];
//             r--;
//         }
//         while (l < interval[i].l)
//         {
//             tmp -= (ll)num[a[l]] * num[a[l]];
//             num[a[l]]--;
//             tmp += (ll)num[a[l]] * num[a[l]];
//             l++;
//         }
//         while (l > interval[i].l)
//         {
//             l--;
//             tmp -= (ll)num[a[l]] * num[a[l]];
//             num[a[l]]++;
//             tmp += (ll)num[a[l]] * num[a[l]];
//         }
//         ans[interval[i].id].a = tmp - (r - l + 1);
//         ans[interval[i].id].b = (ll)(r - l + 1) * (r - l);
//         ans[interval[i].id].reduce();
//     }
// }

// int main()
// {
//     scanf("%d%d", &n, &m);
//     rep1(i, 1, n) scanf("%d", &a[i]);
//     rep1(i, 1, m)
//     {
//         interval[i].id = i; scanf("%d%d", &interval[i].l, &interval[i].r);
//     }
//     unit = (int)sqrt(n);
//     sot(interval, m);
//     solve();
//     rep1(i, 1, m) printf("%lld/%lld\n", ans[i].a, ans[i].b);
//     return 0;
// }

/* basic header */
// #include <bits/stdc++.h>
// /* define */
// #define ll long long
// #define dou double
// #define pb emplace_back
// #define mp make_pair
// #define fir first
// #define sec second
// #define sot(a,b) sort(a+1,a+1+b)
// #define rep1(i,a,b) for(int i=a;i<=b;++i)
// #define rep0(i,a,b) for(int i=a;i<b;++i)
// #define repa(i,a) for(auto &i:a)
// #define eps 1e-8
// #define int_inf 0x3f3f3f3f
// #define ll_inf 0x7f7f7f7f7f7f7f7f
// #define lson curPos<<1
// #define rson curPos<<1|1
// /* namespace */
// using namespace std;
// /* header end */

// const int maxn = 5e4 + 10;
// int tot = 0, n, m, a[maxn], num[maxn], F[maxn], total = 0, head[maxn];
// ll tmp;
// struct Point
// {
//     int x, y, id;
//     bool operator<(const Point &rhs)const
//     {
//         if (x != rhs.x) return x < rhs.x; else return y < rhs.y;
//     }
// } p[maxn], pp[maxn];

// struct BIT
// {
//     int min_val, pos;
//     void init()
//     {
//         min_val = int_inf, pos = -1;
//     }
// } bit[maxn];

// struct Edge
// {
//     int u, v, d;
//     bool operator<(const Edge &rhs)const
//     {
//         return d < rhs.d;
//     }
// } edge[maxn << 2];

// int find(int x)
// {
//     if (F[x] == -1) return x; else return F[x] = find(F[x]);
// }

// void addedge(int u, int v, int d)
// {
//     edge[tot].u = u; edge[tot].v = v; edge[tot++].d = d;
// }

// struct Graph
// {
//     int to, next;
// } e[maxn << 1];

// void _addedge(int u, int v)
// {
//     e[total].to = v;
//     e[total].next = head[u];
//     head[u] = total++;
// }

// int lowbit(int x)
// {
//     return x & -x;
// }

// void update(int i, int val, int pos)
// {
//     while (i > 0)
//     {
//         if (val < bit[i].min_val)
//         {
//             bit[i].min_val = val; bit[i].pos = pos;
//         }
//         i -= lowbit(i);
//     }
// }

// int ask(int i, int m)
// {
//     int min_val = int_inf, pos = -1;
//     while (i <= m)
//     {
//         if (bit[i].min_val < min_val)
//         {
//             min_val = bit[i].min_val;
//             pos = bit[i].pos;
//         }
//         i += lowbit(i);
//     }
//     return pos;
// }

// int dist(const Point &a, const Point &b)
// {
//     return abs(a.x - b.x) + abs(a.y - b.y);
// }

// void manhattan_minimum_spanning_tree(int n, Point p[])
// {
//     int a[maxn], b[maxn]; tot = 0;
//     rep0(dir, 0, 4)
//     {
//         if (dir == 1 || dir == 3)
//             rep0(i, 0, n) swap(p[i].x, p[i].y);
//         else if (dir == 2)
//             rep0(i, 0, n) p[i].x = -p[i].x;
//         sort(p, p + n);
//         int m = unique(b, b + n) - b;
//         rep1(i, 1, m) bit[i].init();
//         for (int i = n - 1; i >= 0; i--)
//         {
//             int pos = lower_bound(b, b + m, a[i]) - b + 1;
//             int ans = ask(pos, m);
//             if (ans != -1) addedge(p[i].id, p[ans].id, dist(p[i], p[ans]));
//             update(pos, p[i].x + p[i].y, i);
//         }
//     }
//     rep0(i, 0, maxn) F[i] = -1, head[i] = -1; sort(edge, edge + tot); total = 0;
//     rep0(i, 0, tot)
//     {
//         int u = edge[i].u, v = edge[i].v, t1 = find(u), t2 = find(v);
//         if (t1 != t2)
//         {
//             F[t1] = t2;
//             _addedge(u, v); _addedge(v, u);
//         }
//     }
// }

// struct Ans
// {
//     ll a, b;
// } ans[maxn];

// void add(int l, int r)
// {
//     rep1(i, l, r)
//     {
//         tmp -= (ll)num[a[i]] * num[a[i]];
//         num[a[i]]++;
//         tmp += (ll)num[a[i]] * num[a[i]];
//     }
// }

// void del(int l, int r)
// {
//     rep1(i, l, r)
//     {
//         tmp -= (ll)num[a[i]] * num[a[i]];
//         num[a[i]]--;
//         tmp += (ll)num[a[i]] * num[a[i]];
//     }
// }

// void dfs(int l1, int r1, int l2, int r2, int idx, int pre)
// {
//     if (l2 < l1) add(l2, l1 - 1);
//     if (r2 > r1) add(r1 + 1, r2);
//     if (l2 > l1) del(l1, l2 - 1);
//     if (r2 < r1) del(r2 + 1, r1);
//     ans[pp[idx].id].a = tmp - (r2 - l2 + 1);
//     ans[pp[idx].id].b = (ll)(r2 - l2 + 1) * (r2 - l2);
//     for (int i = head[idx]; i != -1; i = e[i].next)
//     {
//         int v = e[i].to;
//         if (v == pre) continue;
//         dfs(l2, r2, pp[v].x, pp[v].y, v, idx);
//     }
//     if (l2 < l1) del(l2, l1 - 1);
//     if (r2 > r1) del(r1 + 1, r2);
//     if (l2 > l1) add(l1, l2 - 1);
//     if (r2 < r1) add(r2 + 1, r1);
// }

// int main()
// {
//     scanf("%d%d", &n, &m);
//     rep1(i, 1, n) scanf("%d", &a[i]);
//     rep0(i, 0, m)
//     {
//         scanf("%d%d", &p[i].x, &p[i].y);
//         p[i].id = i; pp[i] = p[i];
//     }
//     manhattan_minimum_spanning_tree(m, p);
//     rep0(i, 0, maxn) num[i] = 0; tmp = 0;
//     dfs(1, 0, pp[0].x, pp[0].y, 0, -1);
//     rep0(i, 0, m)
//     {
//         ll g = __gcd(ans[i].a, ans[i].b);
//         printf("%lld/%lld\n", ans[i].a / g, ans[i].b / g);
//     }
//     return 0;
// }

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define N 50000
#define Q 50000
#define INFI 123456789

typedef long long ll;
struct edge
{
    int next, node;
} e[Q << 1 | 1];
int head[N + 1], tot = 0;
struct point
{
    int x, y, n;
    bool operator < (const point &p) const
    {
        return x == p.x ? y < p.y : x < p.x;
    }
} interval[Q + 1], p[Q + 1];
struct inedge
{
    int a, b, w;
    bool operator < (const inedge &x) const
    {
        return w < x.w;
    }
} ie[Q << 3 | 1];
int cnt = 0;
struct BITnode
{
    int w, p;
} arr[Q + 1];
int n, q, col[N + 1], a[Q + 1], *l[Q + 1], f[N + 1], c[N + 1];
ll cur, ans[Q + 1];
bool v[Q + 1];

template <typename T>
inline T abs(T x)
{
    return x < (T)0 ? -x : x;
}

inline int dist(const point &a, const point &b)
{
    return abs(a.x - b.x) + abs(a.y - b.y);
}

inline void addinedge(int a, int b, int w)
{
    ++cnt;
    ie[cnt].a = a, ie[cnt].b = b, ie[cnt].w = w;
}

inline void addedge(int a, int b)
{
    e[++tot].next = head[a];
    head[a] = tot, e[tot].node = b;
}

inline bool cmp(int *a, int *b)
{
    return *a < *b;
}

inline int query(int x)
{
    int r = INFI, p = -1;
    for (; x <= q; x += x & -x)
        if (arr[x].w < r) r = arr[x].w, p = arr[x].p;
    return p;
}

inline void modify(int x, int w, int p)
{
    for (; x > 0; x -= x & -x)
        if (arr[x].w > w) arr[x].w = w, arr[x].p = p;
}

int find(int x)
{
    return x == f[x] ? x : f[x] = find(f[x]);
}

inline ll calc(int x)
{
    return (ll)x * (x - 1);
}

inline void add(int l, int r)
{
    for (int i = l; i <= r; ++i)
    {
        cur -= calc(c[col[i]]);
        cur += calc(++c[col[i]]);
    }
}

inline void remove(int l, int r)
{
    for (int i = l; i <= r; ++i)
    {
        cur -= calc(c[col[i]]);
        cur += calc(--c[col[i]]);
    }
}

void dfs(int x, int l, int r)
{
    v[x] = true;
    //Process right bound
    if (r < interval[x].y)
        add(r + 1, interval[x].y);
    else if (r > interval[x].y)
        remove(interval[x].y + 1, r);
    //Process left bound
    if (l < interval[x].x)
        remove(l, interval[x].x - 1);
    else if (l > interval[x].x)
        add(interval[x].x, l - 1);
    ans[x] = cur;
    //Moving on to next query
    for (int i = head[x]; i; i = e[i].next)
    {
        if (v[e[i].node]) continue;
        dfs(e[i].node, interval[x].x, interval[x].y);
    }
    //Revert changes
    //Process right bound
    if (r < interval[x].y)
        remove(r + 1, interval[x].y);
    else if (r > interval[x].y)
        add(interval[x].y + 1, r);
    //Process left bound
    if (l < interval[x].x)
        add(l, interval[x].x - 1);
    else if (l > interval[x].x)
        remove(interval[x].x, l - 1);
}

int main()
{
    //Initialize
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", col + i);
    for (int i = 1; i <= q; ++i) scanf("%d%d", &interval[i].x, &interval[i].y);
    //Manhattan MST
    for (int i = 1; i <= q; ++i) p[i] = interval[i], p[i].n = i;
    for (int dir = 1; dir <= 4; ++dir)
    {
        //Coordinate transform
        if (dir == 2 || dir == 4)
            for (int i = 1; i <= q; ++i) std::swap(p[i].x, p[i].y);
        else if (dir == 3)
            for (int i = 1; i <= q; ++i) p[i].x = -p[i].x;
        //Sort by x-coordinate
        std::sort(p + 1, p + q + 1);
        //Discretize
        for (int i = 1; i <= q; ++i) a[i] = p[i].y - p[i].x, l[i] = &a[i];
        std::sort(l + 1, l + q + 1, cmp);
        int cnt = 1;
        for (int i = 2; i <= q; ++i)
            if (*l[i] == *l[i - 1]) *l[i - 1] = cnt;
            else *l[i - 1] = cnt++;
        *l[q] = cnt;
        //Initialize BIT
        for (int i = 1; i <= q; ++i) arr[i].w = INFI, arr[i].p = -1;
        //Find points and add edges
        for (int i = q; i > 0; --i)
        {
            int pos = query(a[i]);
            if (pos != -1)
                addinedge(p[i].n, p[pos].n, dist(p[i], p[pos]));
            modify(a[i], p[i].x + p[i].y, i);
        }
    }
    //Kruskal
    std::sort(ie + 1, ie + cnt + 1);
    //Initialize disjoint set
    for (int i = 1; i <= q; ++i) f[i] = i;
    //Add edges
    for (int i = 1; i <= cnt; ++i)
        if (find(ie[i].a) != find(ie[i].b))
        {
            f[find(ie[i].a)] = find(ie[i].b);
            addedge(ie[i].a, ie[i].b), addedge(ie[i].b, ie[i].a);
        }

    //Modui Algorithm
    ++c[col[1]];
    dfs(1, 1, 1);
    //Output
    for (int i = 1; i <= q; ++i)
    {
        ll x = ans[i], y = calc(interval[i].y - interval[i].x + 1);
        if (!x) printf("0/1\n");
        else
        {
            ll g = __gcd(x, y);
            printf("%lld/%lld\n", x / g, y / g);
        }
    }
    return 0;
}