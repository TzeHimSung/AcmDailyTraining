/* basic header */
#include <iostream>
#include <cstring>
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
int a[maxn];

struct Node {
    int l, r, val[50];
};

Node segt[maxn << 2];

void maintain(Node &fa, Node &ls, Node &rs) {
    int i = 0, j = 0;
    rep0(c, 0, 50) {
        if (i >= 50)
            fa.val[c] = rs.val[j++];
        else if (j >= 50)
            fa.val[c] = ls.val[i++];
        else if (ls.val[i] < rs.val[j])
            fa.val[c] = rs.val[j++];
        else fa.val[c] = ls.val[i++];
    }
}

void build(int curpos, int curl, int curr) {
    segt[curpos].l = curl, segt[curpos].r = curr;
    // memset(segt[curpos].val, 0, sizeof(segt[curpos].val));
    if (curl < curr) { // if is not leaf node
        int mid = curl + curr >> 1;
        build(lson, curl, mid); build(rson, mid + 1, curr);
        maintain(segt[curpos], segt[lson], segt[rson]);
    } else
        segt[curpos].val[0] = a[curl]; // if is leaf node
}

Node query(int curpos, int curl, int curr) {
    if (segt[curpos].l == curl && segt[curpos].r == curr) return segt[curpos];
    else {
        int mid = segt[curpos].l + segt[curpos].r >> 1;
        if (curr <= mid) return query(lson, curl, curr);
        else if (curl > mid) return query(rson, curl, curr);
        else {
            Node lnode = query(lson, curl, mid), rnode = query(rson, mid + 1, curr);
            Node ret; ret.l = curl, ret.r = curr;
            maintain(ret, lnode, rnode);
            return ret;
        }
    }
}

int main() {
    int n, q;
    while (~scanf("%d%d", &n, &q)) {
        rep1(i, 1, n) scanf("%d", &a[i]);
        build(1, 1, n);
        while (q--) {
            int l, r; scanf("%d%d", &l, &r);
            Node cur = query(1, l, r);
            ll ans = -1;
            rep0(i, 0, 48) {
                if ((ll)cur.val[i] < (ll)cur.val[i + 1] + (ll)cur.val[i + 2]) {
                    ans = (ll)cur.val[i] + (ll)cur.val[i + 1] + (ll)cur.val[i + 2];
                    break;
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}