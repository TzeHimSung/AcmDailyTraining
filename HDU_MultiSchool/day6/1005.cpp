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

const int maxn = 2e3 + 10, maxm = 4e3 + 10;
struct Point {
    int x, y, z;
    bool operator<(const Point &rhs) const {
        return x < rhs.x;
    }
} e[maxn];

struct Node {
    int pre, suf, s, v;
} segt[maxm];

int pos[maxn];

void build(int curpos, int curl, int curr) {
    segt[curpos].pre = segt[curpos].suf = segt[curpos].s = segt[curpos].v = 0;
    if (curl == curr) {
        pos[curl] = curpos;
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
}

void change(int curpos, int p) {
    curpos = pos[curpos];
    segt[curpos].s += p;
    if (segt[curpos].s > 0)
        segt[curpos].pre = segt[curpos].suf = segt[curpos].v = segt[curpos].s;
    else
        segt[curpos].pre = segt[curpos].suf = segt[curpos].v = 0;
    for (curpos >>= 1; curpos; curpos >>= 1) {
        segt[curpos].pre = max(segt[lson].pre, segt[lson].s + segt[rson].pre);
        segt[curpos].suf = max(segt[rson].suf, segt[rson].s + segt[lson].suf);
        segt[curpos].s = segt[lson].s + segt[rson].s;
        segt[curpos].v = max(max(segt[lson].v, segt[rson].v), segt[lson].suf + segt[rson].pre);
    }
}

int main() {
    int casenum; scanf("%d", &casenum);
    while (casenum--) {
        int n, tot = 0, tot2 = 0, b[maxn];
        ll ans = 0;
        scanf("%d", &n);
        rep1(i, 1, n) {
            scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].z);
            b[++tot] = e[i].y;
        }
        sot(b, tot);
        rep1(i, 1, tot)
        if (i == 1 || b[i] != b[tot2]) b[++tot2] = b[i];
        sot(e, n);
        rep1(i, 1, n) e[i].y = lower_bound(b + 1, b + 1 + tot2, e[i].y) - b;
        int j, k;
        for (int i = 1; i <= n; i++)
            if (i == 1 || e[i].x != e[i - 1].x) {
                build(1, 1, tot2);
                for (j = i; j <= n; j = k) {
                    for (k = j; k <= n && e[j].x == e[k].x; k++) change(e[k].y, e[k].z);
                    if (ans < segt[1].v) ans = segt[1].v;
                }
            }
        printf("%lld\n", ans);
    }
    return 0;
}