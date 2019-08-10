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

const int maxn = 1e6 + 10;
int a[maxn], root[maxn], cnt = 0;

struct Node {
    int l, r, sum;
} segt[maxn * 40];

void update(int pos, int curl, int curr, int &curroot, int &lastroot) {
    segt[++cnt] = segt[lastroot], segt[cnt].sum++, curroot = cnt;
    if (curl == curr) return;
    int mid = curl + curr >> 1;
    if (pos <= mid) update(pos, curl, mid, segt[curroot].l, segt[lastroot].l);
    else update(pos, mid + 1, curr, segt[curroot].r, segt[lastroot].r);
}

int query(int lRoot, int rRoot, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr)
        return segt[rRoot].sum - segt[lRoot].sum;
    if (curl == curr) return 0;
    int mid = curl + curr >> 1;
    if (qr <= mid) return query(segt[lRoot].l, segt[rRoot].l, curl, mid, ql, qr);
    else if (ql > mid) return query(segt[lRoot].r, segt[rRoot].r, mid + 1, curr, ql, qr);
    else return query(segt[lRoot].l, segt[rRoot].l, curl, mid, ql, mid) + query(segt[lRoot].r, segt[rRoot].r, mid + 1, curr, mid + 1, qr);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        cnt = 0;
        int n, q, maxx; scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            maxx = max(maxx, a[i]);
        }
        for (int i = 1; i <= n; i++)
            update(a[i], 1, maxx, root[i], root[i - 1]);
        int lastAns = 0;
        while (q--) {
            int l, r, p, k; scanf("%d%d%d%d", &l, &r, &p, &k);
            l ^= lastAns, r ^= lastAns, p ^= lastAns, k ^= lastAns;
            int upBound = maxx, lowBound = 0, ans = maxx;
            while (lowBound <= upBound) {
                int mid = lowBound + upBound >> 1;
                if (query(root[l - 1], root[r], 1, maxx, p - mid, p + mid) >= k) {
                    ans = mid;
                    upBound = mid - 1;
                } else lowBound = mid + 1;
            }
            lastAns = ans;
            printf("%d\n", ans);
        }
    }
    return 0;
}