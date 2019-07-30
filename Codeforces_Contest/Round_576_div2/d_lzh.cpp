#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define up(i, a, b) for (int i = (a); i <= (b); i++)
#define down(i, a, b) for (int i = (a); i >= (b); i--)
#define mem(x, y) memset(x, (y), sizeof x)
#define ff first
#define ss second
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define sc(a) scanf("%d", &a)
#define scl(a) scanf("%lld", &a)
#define scs(a) scanf("%s", a)
#define pr(a, b) printf("%d%c", a, b)
#define prl(a, b) printf("%lld%c", a, b)
#define PQ priority_queue
#define ld long double
#define all(v) v.begin(), v.end()
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

typedef pair<int, int> pii;
typedef vector<int> V;

struct node {
    int l, r, val, add;
} tr[800010];
int a[200010], ans[200010];

void build(int x, int l, int r) {
    tr[x].l = l, tr[x].r = r;
    if (l == r) {
        tr[x].add = 0;
        tr[x].val = a[l];
        return;
    }
    int mid = l + r >> 1;
    build(x << 1, l, mid), build(x << 1 | 1, mid + 1, r);
}

void update(int x, int q, int val) {
    if (tr[x].l == q && tr[x].r == q) {
        tr[x].val = val, tr[x].add = 0;
        return;
    }
    int mid = tr[x].l + tr[x].r >> 1;
    tr[x << 1].add = max(tr[x << 1].add, tr[x].add);
    tr[x << 1 | 1].add = max(tr[x << 1 | 1].add, tr[x].add);
    tr[x].add = 0;
    if (q <= mid)update(x << 1, q, val);
    else update(x << 1 | 1, q, val);
}

void query(int x) {
    if (tr[x].l == tr[x].r) {
        ans[tr[x].l] = max(tr[x].val, tr[x].add);
        return;
    }
    tr[x << 1].add = max(tr[x << 1].add, tr[x].add);
    tr[x << 1 | 1].add = max(tr[x << 1 | 1].add, tr[x].add);
    query(x << 1), query(x << 1 | 1);
}

int main() {
    int n;
    sc(n);
    up(i, 1, n)sc(a[i]);
    build(1, 1, n);
    int q;
    sc(q);
    up(i, 1, q) {
        int x, y, z;
        sc(x);
        if (x == 1) {
            sc(y), sc(z);
            update(1, y, z);
        } else sc(y), tr[1].add = max(tr[1].add, y);
    }
    query(1);
    up(i, 1, n)pr(ans[i], ' ');
}