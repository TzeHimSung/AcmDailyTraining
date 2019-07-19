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
#define lson (curpos<<1)
#define rson (curpos<<1|1)
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;

struct Point {
    int x, y, a, b;
    bool operator<(const Point &rhs) const {
        if (x == rhs.x) return y > rhs.y;
        return x < rhs.x;
    }
} p[maxn];
int n, b[maxn];
ll lazy[maxn << 2], segt[maxn << 2];

void pushup(int curpos) {
    segt[curpos] = max(segt[lson], segt[rson]);
}

void pushdown(int curpos) {
    if (lazy[curpos]) {
        lazy[lson] += lazy[curpos];
        segt[lson] += lazy[curpos];
        lazy[rson] += lazy[curpos];
        segt[rson] += lazy[curpos];
        lazy[curpos] = 0;
    }
}

void build(int curpos, int curl, int curr) {
    segt[curpos] = lazy[curpos] = 0;
    if (curl == curr)
        return;
    build(lson, curl, mid);
    build(rson, mid + 1, curr);
}

void update(int curpos, int curl, int curr, int pos, ll val) {
    if (curl == curr) {
        segt[curpos] = val;
        return;
    }
    pushdown(curpos);
    if (pos <= mid)
        update(lson, curl, mid, pos, val);
    else
        update(rson, mid + 1, curr, pos, val);
    pushup(curpos);
}

void update(int curpos, int curl, int curr, int ql, int qr, ll val) {
    if (ql <= curl && curr <= qr) {
        segt[curpos] += val;
        lazy[curpos] += val;
        return;
    }
    pushdown(curpos);
    if (ql <= mid)
        update(lson, curl, mid, ql, qr, val);
    if (qr > mid)
        update(rson, mid + 1, curr, ql, qr, val);
    pushup(curpos);
}

ll query(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr)
        return segt[curpos];
    pushdown(curpos);
    ll ans = -1e18;
    if (ql <= mid)
        ans = max(ans, query(lson, curl, mid, ql, qr));
    if (qr > mid)
        ans = max(ans, query(rson, mid + 1, curr, ql, qr));
    return ans;
}

int main() {
    while (~scanf("%d", &n)) {
        rep1(i, 1, n) {
            scanf("%d%d%d%d", &p[i].x, &p[i].y, &p[i].a, &p[i].b);
            b[i] = p[i].y;
        }
        sot(p, n);
        b[n + 1] = 0;
        sot(b, n + 1);
        int m = unique(b + 1, b + n + 2) - b - 1;
        build(1, 1, m);
        rep1(i, 1, n) {
            int y = lower_bound(b + 1, b + m + 1, p[i].y) - b;
            ll r = query(1, 1, m, 1, y);
            update(1, 1, m, y, r + p[i].b);
            if (y > 1) {
                update(1, 1, m, 1, y - 1, p[i].a);
            }
            if (y < m) {
                update(1, 1, m, y + 1, m, p[i].b);
            }
        }
        printf("%lld\n", query(1, 1, m, 1, m));
    }
    return 0;
}