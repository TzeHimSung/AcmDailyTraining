#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct perminent_segment_tree {
    struct node {
        int l, r, lc, rc, val;
    } tr[2000001];
    int ver[200001];
    int num, vernum;
    void setRange(int l, int r) {
        num = 0;
        vernum = 0;
        ver[0] = 0;
        build(l, r, 0);
    }
    void build(int l, int r, int now) {
        tr[now].l = l; tr[now].r = r; tr[now].val = 0;
        if (l < r) {
            int mid = (l + r) >> 1;
            ++num; tr[now].lc = num;
            ++num; tr[now].rc = num;
            build(l, mid, tr[now].lc);
            build(mid + 1, r, tr[now].rc);
        }
    }
    void pushup(node &f, node &l, node &r) {
        f.val = l.val + r.val;
    }
    void add(int pos, int val) {
        ++vernum;
        ver[vernum] = update(pos, val, ver[vernum - 1]);
    }
    int update(int pos, int val, int now) {
        int t = ++num;
        tr[t] = tr[now];
        if (tr[t].l == tr[t].r) {
            tr[t].val += val;
        } else {
            int mid = tr[now].l + tr[now].r >> 1;
            if (pos <= mid) tr[t].lc = update(pos, val, tr[t].lc);
            else tr[t].rc = update(pos, val, tr[t].rc);
            pushup(tr[t], tr[tr[t].lc], tr[tr[t].rc]);
        }
        return t;
    }

    int query(int l, int r, int now1, int now2) {
        if (tr[now1].l == l && tr[now1].r == r) {
            return tr[now2].val - tr[now1].val;
        }
        int mid = tr[now1].l + tr[now1].r >> 1;
        if (r <= mid) return query(l, r, tr[now1].lc, tr[now2].lc);
        else if (l > mid) return query(l, r, tr[now1].rc, tr[now2].rc);
        else return query(l, mid, tr[now1].lc, tr[now2].lc) + query(mid + 1, r, tr[now1].rc, tr[now2].rc);
    }

};
perminent_segment_tree tr;
int a[200001], b[200001];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b, b + n);
        int len = unique(b, b + n) - b;
        tr.setRange(0, len - 1);
        for (int i = 0; i < n; ++i) {
            int t = lower_bound(b, b + len, a[i]) - b;
            tr.add(t, 1);
        }
        int X = 0;
        for (int i = 0; i < m; ++i) {
            int l, r, p, k;
            scanf("%d%d%d%d", &l, &r, &p, &k);
            l ^= X; r ^= X; p ^= X; k ^= X;
            int L = -1, R = max(abs(p - b[0]), abs(p - b[len - 1])) + 1;
            while (L + 1 < R) {
                int mid = L + R >> 1;
                int t1 = lower_bound(b, b + len, p - mid) - b;
                int t2 = upper_bound(b, b + len, p + mid) - b - 1;
                int s;
                if (t1 <= t2) s = tr.query(t1, t2, tr.ver[l - 1], tr.ver[r]);
                else s = 0;

                if (s >= k) R = mid;
                else L = mid;
            }
            X = R;
            printf("%d\n", X);
        }
    }
}
