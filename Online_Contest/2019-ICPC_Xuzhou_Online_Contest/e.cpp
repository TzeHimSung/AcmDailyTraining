/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int read(void) {
    char ch;
    do {
        ch = getchar();
    } while (!isdigit(ch));
    int ret = 0;
    while (isdigit(ch)) {
        ret *= 10;
        ret += ch - '0';
        ch = getchar();
    };
    return ret;
}

const int maxn = 5e5 + 10;
struct Node {
    int maxn;
} segt[maxn << 2];

int n, m, ans[maxn];
pair<int, int> a[maxn];

void maintain(int curpos) {
    segt[curpos].maxn = max(segt[lson].maxn, segt[rson].maxn);
}

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].maxn = a[curl].second;
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

int query(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr) {
        return segt[curpos].maxn;
    }
    int mid = curl + curr >> 1, ret = -1;
    if (ql <= mid) ret = max(ret, query(lson, curl, mid, ql, qr));
    if (mid < qr) ret = max(ret, query(rson, mid + 1, curr, ql, qr));
    return ret;
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        a[i].first = read();
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            ans[a[i].second] = -1;
            break;
        }
        int queryL = lower_bound(a + 1, a + 1 + n, mp(a[i].first + m, 0)) - (a + 1) + 1;
        int maxPos = query(1, 1, n, queryL, n);
        if (maxPos > a[i].second) ans[a[i].second] = maxPos - a[i].second - 1;
        else ans[a[i].second] = -1;
    }
    for (int i = 1; i < n; i++) printf("%d ", ans[i]);
    printf("%d\n", ans[n]);
    return 0;
}