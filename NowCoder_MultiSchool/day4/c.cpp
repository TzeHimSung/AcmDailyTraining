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

const int maxn = 3e6 + 10;
struct Node {
    ll maxx, minn;
} segt[maxn << 2];
ll a[maxn], b[maxn], _b[maxn], ans = -1e18;
int n, l[maxn], r[maxn];

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].maxx = segt[curpos].minn = b[curl];
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    segt[curpos].maxx = max(segt[lson].maxx, segt[rson].maxx);
    segt[curpos].minn = min(segt[lson].minn, segt[rson].minn);
}

ll queryMax(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr) return segt[curpos].maxx;
    int mid = curl + curr >> 1;
    if (qr <= mid) return queryMax(lson, curl, mid, ql, qr);
    if (ql > mid) return queryMax(rson, mid + 1, curr, ql, qr);
    return max(queryMax(lson, curl, mid, ql, mid), queryMax(rson, mid + 1, curr, mid + 1, qr));
}

ll queryMin(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr) return segt[curpos].minn;
    int mid = curl + curr >> 1;
    if (qr <= mid) return queryMin(lson, curl, mid, ql, qr);
    if (ql > mid) return queryMin(rson, mid + 1, curr, ql, qr);
    return min(queryMin(lson, curl, mid, ql, mid), queryMin(rson, mid + 1, curr, mid + 1, qr));
}

int main() {
    b[0] = 0;
    scanf("%d", &n);
    rep1(i, 1, n) scanf("%lld", &a[i]);
    rep1(i, 1, n) {
        scanf("%lld", &b[i]); _b[i] = b[i];
        b[i] += b[i - 1];
    }
    build(1, 1, n);
    rep1(i, 1, n) {
        l[i] = r[i] = i;
        while (l[i] > 1 && a[l[i] - 1] >= a[i]) l[i]--;
        while (r[i] < n && a[r[i] + 1] >= a[i]) r[i]++;
        if (a[i] > 0) {
            ll ls = b[i] - queryMin(1, 1, n, l[i], i), rs = queryMax(1, 1, n, i, r[i]) - b[i];
            ans = max(ans, a[i] * (rs + ls - _b[i]));
        } else {
            ll ls = queryMax(1, 1, n, l[i], i), rs = queryMin(1, 1, n, i, r[i]) - b[i];
            ans = max(ans, a[i] * (rs + ls - _b[i]));
        }
    }
    printf("%lld\n", ans);
    return 0;
}