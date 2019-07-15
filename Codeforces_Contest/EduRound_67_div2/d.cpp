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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 3e5 + 10;
int t, n, segt[maxn << 2], a[maxn], b[maxn];
vector<int>pos[maxn];

void build(int curpos, int curl, int curr) {
    segt[curpos] = a[curl];
    if (curl == curr) return;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    segt[curpos] = min(segt[lson], segt[rson]);
}

int query(int curpos, int curl, int curr, int ql, int qr) {
    if (ql <= curl && curr <= qr) return segt[curpos];
    if (qr <= mid) return query(lson, curl, mid, ql, qr);
    else if (ql > mid) return query(rson, mid + 1, curr, ql, qr);
    else return min(query(lson, curl, mid, ql, mid), query(rson, mid + 1, curr, mid + 1, qr));
}

void update(int curpos, int curl, int curr, int pos, int val) {
    if (curl == curr) {
        segt[curpos] = val;
        return;
    }
    if (pos <= mid) update(lson, curl, mid, pos, val);
    else update(rson, mid + 1, curr, pos, val);
    segt[curpos] = min(segt[lson], segt[rson]);
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        rep1(i, 1, n) pos[i].clear();
        rep1(i, 1, n) scanf("%d", &a[i]);
        for (int i = n; i > 0; i--) pos[a[i]].pb(i);
        rep1(i, 1, n) scanf("%d", &b[i]);
        int flag = 1;
        build(1, 1, n);
        rep1(i, 1, n) {
            int k = b[i];
            if (pos[k].empty()) { // no element can be choisen to swap
                flag = 0; break;
            }
            int x = *(--pos[k].end()); // get the last element of vector pos[k]
            if (query(1, 1, n, 1, x) != k) { // the mininum of interval is not current b[i], no solution obviously
                flag = 0; break;
            }
            update(1, 1, n, x, int_inf); // current b[i] is ok, make it into inf to eliminate the affect
        }
        if (flag) puts("YES"); else puts("NO");
    }
    return 0;
}