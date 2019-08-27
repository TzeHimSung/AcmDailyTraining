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

const int maxn = 2e5 + 10;
struct Node {
    ll minn, tag;
} segt[maxn << 2];
int n, a[maxn];
ll p[maxn];

void maintain(int curpos) {
    segt[curpos].minn = min(segt[lson].minn, segt[rson].minn);
}

void pushdown(int curpos) {
    segt[lson].tag += segt[curpos].tag; segt[rson].tag += segt[curpos].tag;
    segt[lson].minn += segt[curpos].tag; segt[rson].minn += segt[curpos].tag;
    segt[curpos].tag = 0;
}

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].minn = p[curl];
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

void update(int curpos, int curl, int curr, int ql, int qr, ll val) {
    if (ql <= curl && curr <= qr) {
        segt[curpos].tag += val;
        segt[curpos].minn += val;
        return;
    }
    int mid = curl + curr >> 1;
    if (ql <= mid) update(lson, curl, mid, ql, qr, val);
    if (mid < qr) update(rson, mid + 1, curr, ql, qr, val);
    maintain(curpos);
}

ll queryMin(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr)
        return segt[curpos].minn;
    pushdown(curpos);
    int mid = curl + curr >> 1;
    ll ans = ll_inf;
    if (ql <= mid) ans = min(ans, queryMin(lson, curl, mid, ql, qr));
    if (mid < qr) ans = min(ans, queryMin(rson, mid + 1, curr, ql, qr));
    return ans;
}

ll queryLastZero(int curpos, int curl, int curr) {
    if (curl == curr)
        return curl;
    int mid = curl + curr >> 1;
    if (queryMin(1, 1, n, mid + 1, curr) == 0)
        return queryLastZero(rson, mid + 1, curr);
    else return queryLastZero(lson, curl, mid);
    maintain(curpos);
}

int main() {
    scanf("%d", &n);
    rep1(i, 1, n) scanf("%lld", &p[i]);
    build(1, 1, n);
    rep1(i, 1, n) {
        int pos = queryLastZero(1, 1, n);
        a[pos] = i;
        update(1, 1, n, pos + 1, n, -i);
        update(1, 1, n, pos, pos, ll_inf + i);
    }
    rep1(i, 1, n) printf("%d ", a[i]);
    puts("");
    return 0;
}