#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 200010, INF = 1e8;
struct P {
    int x, v;
} p[MAXN];
int n, tot, rt, ch[MAXN << 5][2];
ll ans, val[MAXN << 5], cnt[MAXN << 5];
bool cmp (P a, P b) {
    return a.x < b.x;
}
void modify (int &p, int l, int r, int pos, int v1, int v2) {
    if (!p) {
        p = ++tot;
    }
    if (l == r) {
        cnt[p] += v1, val[p] += v2;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) {
        modify(ch[p][0], l, mid, pos, v1, v2);
    } else {
        modify(ch[p][1], mid + 1, r, pos, v1, v2);
    }
    val[p] = val[ch[p][0]] + val[ch[p][1]];
    cnt[p] = cnt[ch[p][0]] + cnt[ch[p][1]];
    return;
}
ll query1 (int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return cnt[p];
    }
    int mid = (l + r) >> 1;
    return query1(ch[p][0], l, mid, ql, qr) + query1(ch[p][1], mid + 1, r, ql, qr);
}
ll query2 (int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) {
        return 0;
    }
    if (ql <= l && r <= qr) {
        return val[p];
    }
    int mid = (l + r) >> 1;
    return query2(ch[p][0], l, mid, ql, qr) + query2(ch[p][1], mid + 1, r, ql, qr);
}
int main () {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].x);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i].v);
    }
    // 按位置大小排序
    sort(p + 1, p + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        ans += query1(rt, -INF, INF, -INF, p[i].v) * p[i].x - query2(rt, -INF, INF, -INF, p[i].v);
        modify(rt, -INF, INF, p[i].v, 1, p[i].x);
    }
    printf("%lld\n", ans);
    return 0;
}