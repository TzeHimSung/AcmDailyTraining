#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
struct LinerBase {
    int cnt;
    LL b[32];
    void init() {
        cnt = 0;
        memset(b, 0, sizeof b);
    }
    bool insert(LL x) {
        for (int i = 31; i >= 0; i--) {
            if (x & (1ll << i)) {
                if (b[i])
                    x ^= b[i];
                else {
                    b[i] = x;
                    cnt ++;
                    return 1;
                }
            }
        }
        return 0;
    }
    bool check(LL x) {
        for (int i = 31; i >= 0; i--) {
            if (x & (1ll << i))
                x ^= b[i];
        }
        return x == 0;
    }
};
LinerBase merge(LinerBase &a, LinerBase &b) {
    LinerBase c, d, All;
    for (int i = 31; i >= 0; i--) {
        c.b[i] = 0;
        All.b[i] = a.b[i];
        d.b[i] = 1ll << i;
    }
    for (int i = 31; i >= 0; i--) {
        if (b.b[i]) {
            LL v = b.b[i], k = 0; bool jud = 1;
            for (int j = 31; j >= 0; j--) {
                if ((1ll << j)&v) {
                    if (All.b[j]) {
                        v ^= All.b[j];
                        k ^= d.b[j];
                    } else {
                        jud = 0;
                        All.b[j] = v;
                        d.b[j] = k;
                        break;
                    }
                }
            }
            if (jud) {
                LL cur = 0;
                for (int j = 31; j >= 0; j--)
                    if (k & (1ll << j))
                        cur ^= a.b[j];
                c.insert(cur);
            }
        }
    }
    return c;
}
LinerBase st[MAXN << 2];
LinerBase a[MAXN];
void push_up(int rt) {
    st[rt] = merge(st[rt << 1], st[rt << 1 | 1]);
}
void build(int l, int r, int rt) {
    if (l == r) {
        st[rt] = a[l];
        return;
    }
    int m = l + r >> 1;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    push_up(rt);
}
bool query(int l, int r, int ql, int qr, int rt, LL x) {
    if (ql <= l && r <= qr)
        return st[rt].check(x);
    int m = l + r >> 1;
    if (ql > m)
        return query(m + 1, r, ql, qr, rt << 1 | 1, x);
    if (qr <= m)
        return query(l, m, ql, qr, rt << 1, x);
    return query(l, m, ql, qr, rt << 1, x) && query(m + 1, r, ql, qr, rt << 1 | 1, x);
}
int main() {
    int n, m, i, j, sz, l, r;
    LL x;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) {
        scanf("%d", &sz);
        for (j = 0; j < sz; j++) {
            scanf("%lld", &x);
            a[i].insert(x);
        }
    }
    build(1, n, 1);
    while (m--) {
        scanf("%d%d%lld", &l, &r, &x);
        if (query(1, n, l, r, 1, x))
            printf("YES\n");
        else
            printf("NO\n");
    }
}