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
struct LinerBase {
    int cnt;
    ll b[32];
    void init() {
        cnt = 0;
        memset(b, 0, sizeof(b));
    }
    int insert(ll x) {
        for (int i = 31; i >= 0; i--)
            if (x & (1ll << i)) {
                if (b[i]) x ^= b[i];
                else {
                    b[i] = x;
                    cnt++;
                    return 1;
                }
            }
        return 0;
    }
    bool check(ll x) {
        for (int i = 31; i >= 0; i--)
            if (x & (1ll << i)) x ^= b[i];
        return x == 0;
    }
};

LinerBase merge(LinerBase &a, LinerBase &b) {
    LinerBase c, d, all;
    for (int i = 31; i >= 0; i--) {
        c.b[i] = 0;
        all.b[i] = a.b[i];
        d.b[i] = 1ll << i;
    }
    for (int i = 31; i >= 0; i--)
        if (b.b[i]) {
            ll v = b.b[i], k = 0; int jud = 1;
            for (int j = 31; j >= 0; j--)
                if ((1ll << j) & v)
                    if (all.b[j]) {
                        v ^= all.b[j];
                        k ^= d.b[j];
                    } else {
                        jud = 0;
                        all.b[j] = v;
                        d.b[j] = k;
                        break;
                    }
            if (jud) {
                ll cur = 0;
                for (int j = 31; j >= 0; j--)
                    if (k & (1ll << j)) cur ^= a.b[j];
                c.insert(cur);
            }
        }
    return c;
}
LinerBase segt[maxn << 2], a[maxn];

void maintain(int curpos) {
    segt[curpos] = merge(segt[lson], segt[rson]);
}

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos] = a[curl];
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

bool query(int curpos, ll x, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr)
        return segt[curpos].check(x);
    int mid = curl + curr >> 1;
    if (qr <= mid) return query(lson, x, curl, mid, ql, qr);
    if (ql > mid) return query(rson, x, mid + 1, curr, ql, qr);
    return query(lson, x, curl, mid, ql, qr) && query(rson, x, mid + 1, curr, ql, qr);
}

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    rep1(i, 1, n) {
        int _size; scanf("%d", &_size);
        rep1(j, 1, _size) {
            ll x; scanf("%lld", &x);
            a[i].insert(x);
        }
    }
    build(1, 1, n);
    while (m--) {
        int l, r; ll x; scanf("%d%d%lld", &l, &r, &x);
        if (query(1, x, 1, n, l, r)) puts("YES");
        else puts("NO");
    }
    return 0;
}
