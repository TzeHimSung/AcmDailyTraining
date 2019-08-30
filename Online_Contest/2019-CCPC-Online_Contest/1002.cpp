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

int read() {
    int ret = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') ch = getchar();
    while (ch >= '0' && ch <= '9') {
        ret = (ret << 1) + (ret << 3) + ch - '0';
        ch = getchar();
    }
    return ret;
}

const int maxn = 1e5 + 10;
int n, m, a[maxn], id[maxn];
struct Node {
    int maxx;
} segt[maxn << 2];

inline void maintain(int curpos) {
    segt[curpos].maxx = max(segt[lson].maxx, segt[rson].maxx);
}

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].maxx = id[curl];
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

void update(int curpos, int pos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].maxx = int_inf;
        return;
    }
    int mid = curl + curr >> 1;
    if (pos <= mid) update(lson, pos, curl, mid);
    else update(rson, pos, mid + 1, curr);
    maintain(curpos);
}

int query(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr)
        return segt[curpos].maxx;
    int mid = curl + curr >> 1;
    if (qr <= mid) return query(lson, curl, mid, ql, qr);
    else if (ql > mid) return query(rson, mid + 1, curr, ql, qr);
    return max(query(lson, curl, mid, ql, mid), query(rson, mid + 1, curr, mid + 1, qr));
}

int solve(int R, int k) {
    int LL = k, RR = n + 1, ans = n + 1;
    while (LL <= RR) {
        int mid = LL + RR >> 1;
        if (query(1, 1, n + 1, k, mid) > R) {
            ans = mid;
            RR = mid - 1;
        } else {
            LL = mid + 1;
        }
    }
    return ans;
}

int main() {
    int t = read();
    while (t--) {
        int lastAns = 0;
        n = read(), m = read();
        for (int i = 1; i <= n; i++) {
            a[i] = read();
            id[a[i]] = i;
        }
        id[n + 1] = int_inf;
        build(1, 1, n + 1);
        while (m--) {
            int op = read();
            if (op == 1) {
                int pos = read();
                pos ^= lastAns;
                update(1, a[pos], 1, n + 1);
            } else {
                int r = read(), k = read();
                r ^= lastAns, k ^= lastAns;
                lastAns = solve(r, k);
                printf("%d\n", lastAns);
            }
        }
    }
    return 0;
}