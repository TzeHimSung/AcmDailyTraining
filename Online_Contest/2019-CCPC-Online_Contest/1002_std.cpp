#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int N, M, K;
int a[maxn], id[maxn];

struct Tree {
    int l, r, maxx;
} segt[maxn << 2];

inline void maintain(int curpos) {
    segt[curpos].maxx = max(segt[curpos << 1].maxx, segt[curpos << 1 | 1].maxx);
}

inline void Build(int curpos, int l, int r) {
    segt[curpos].l = l; segt[curpos].r = r;
    if (l == r) {
        segt[curpos].maxx = id[l];
        return;
    }
    int mid = l + r >> 1;
    Build(curpos << 1, l, mid); Build(curpos << 1 | 1, mid + 1, r);
    maintain(curpos);
}

inline void update(int curpos, int pos) {
    if (segt[curpos].l == segt[curpos].r) { // curl==curr
        segt[curpos].maxx = INF;
        return;
    }
    int mid = (segt[curpos].l + segt[curpos].r) >> 1;
    if (pos <= mid) update(curpos << 1, pos);
    else update(curpos << 1 | 1, pos);
    maintain(curpos);
}

inline int query(int curpos, int l, int r) {
    if (l <= segt[curpos].l && segt[curpos].r <= r)
        return segt[curpos].maxx;
    int mid = (segt[curpos].l + segt[curpos].r) >> 1;
    if (r <= mid) return query(curpos << 1, l, r);
    else if (l > mid) return query(curpos << 1 | 1, l, r);
    return max(query(curpos << 1, l, mid), query(curpos << 1 | 1, mid + 1, r));
}

inline int solve(int k, int R) {
    int ll = k, rr = N + 1, ans = N + 1;
    while (ll <= rr) {
        int mid = ll + rr >> 1;
        int tmp = query(1, k, mid);
        if (tmp > R) {
            ans = mid;
            rr = mid - 1;
        } else {
            ll = mid + 1;
        }
    }
    return ans;
}
int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        for (int i = 1; i <= N ; i++) scanf("%d", &a[i]), id[a[i]] = i;
        id[N + 1] = INF;
        Build(1, 1, N + 1);
        int ans = 0;
        while (M--) {
            int op; scanf("%d", &op);
            if (op == 1) {
                int pos; scanf("%d", &pos);
                pos ^= ans;
                update(1, a[pos]);
            } else {
                int r, k; scanf("%d%d", &r, &k);
                r ^= ans; k ^= ans;
                printf("%d\n", ans = solve(k, r));
            }
        }
    }
    return 0;
}