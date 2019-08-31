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
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int n, a[maxn];
map<int, int>last;
pair<int, int> x[maxn], y[maxn];

struct Node {
    ll minn, t, lazy;
    Node() {}
    Node(int a, int b, int c): minn(a), t(b), lazy(c) {}
} segt[maxn << 2];

void maintain(int curpos) {
    segt[curpos].minn = min(segt[lson].minn, segt[rson].minn);
}

void pushdown(int curpos) {
    segt[lson].lazy += segt[curpos].lazy;
    segt[rson].lazy += segt[curpos].lazy;
    segt[lson].minn += segt[curpos].lazy;
    segt[rson].minn += segt[curpos].lazy;
    segt[curpos].lazy = 0;
}

void build(int curpos, int curl, int curr) {
    segt[curpos] = Node(0, 0, 0);
    if (curl == curr) {
        segt[curpos].t = 1;
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
}

void update(int curpos, int curl, int curr, int ql, int qr, ll val) {
    if (ql == curl && curr == qr) {
        segt[curpos].lazy += val;
        segt[curpos].minn += val;
        return;
    }
    if (segt[curpos].lazy) pushdown(curpos);
    int mid = curl + curr >> 1;
    if (qr <= mid) update(lson, curl, mid, ql, qr, val);
    else if (ql > mid) update(rson, mid + 1, curr, ql, qr, val);
    else { // maintain both
        update(lson, curl, mid, ql, mid, val);
        update(rson, mid + 1, curr, mid + 1, qr, val);
    }
    maintain(curpos);
    if (segt[lson].minn == segt[rson].minn)
        segt[curpos].t = segt[lson].t + segt[rson].t;
    else if (segt[rson].minn == segt[curpos].minn)
        segt[curpos].t = segt[rson].t;
    else if (segt[lson].minn == segt[curpos].minn)
        segt[curpos].t = segt[lson].t;
}

pair<int, int> solve(int curpos, int curl, int curr, int ql, int qr) {
    if (ql == curl && qr == curr)
        return mp(segt[curpos].minn, segt[curpos].t);
    if (segt[curpos].lazy) pushdown(curpos);
    int mid = curl + curr >> 1;
    if (qr <= mid) return solve(lson, curl, mid, ql, qr);
    else if (ql > mid) return solve(rson, mid + 1, curr, ql, qr);
    else {
        pair<int, int> lp = solve(lson, curl, mid, ql, mid);
        pair<int, int> rp = solve(rson, mid + 1, curr, mid + 1, qr);
        if (lp.first == rp.first)
            return mp(lp.first, lp.second + rp.second);
        return min(lp, rp);
    }
}

int main() {
    int t; scanf("%d", &t);
    for (int __ = 1; __ <= t; __++) {
        ll ans = 0;
        last.clear();
        scanf("%d", &n);
        build(1, 1, n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int p1 = 0, p2 = 0;
        for (int i = 1; i <= n; i++) {
            while (p1 && a[i] > x[p1].first) {
                update(1, 1, n, x[p1 - 1].second + 1, x[p1].second, a[i] - x[p1].first);
                p1--;
            }
            x[++p1] = mp(a[i], i);
            while (p2 && a[i] < y[p2].first) {
                update(1, 1, n, y[p2 - 1].second + 1, y[p2].second, y[p2].first - a[i]);
                p2--;
            }
            y[++p2] = mp(a[i], i);
            update(1, 1, n, last[a[i]] + 1, i, -1);
            last[a[i]] = i;
            pair<int, int> curr = solve(1, 1, n, 1, i);
            if (curr.first == -1) ans += curr.second;
        }
        printf("Case #%d: %lld\n", __, ans);
    }
    return 0;
}