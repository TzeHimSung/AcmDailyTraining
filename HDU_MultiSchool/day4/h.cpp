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
int a[maxn], b[maxn];

struct ChairmanTree {
    struct Node {
        int l, r, lc, rc, val;
    } segt[maxn * 25];

    int ver[maxn];
    int num, totVer;

    void buildTree(int l, int r) {
        num = 0;
        totVer = 0;
        ver[0] = 0;
        build(0, l, r);
    }

    void build(int curpos, int l, int r) {
        segt[curpos].l = l; segt[curpos].r = r; segt[curpos].val = 0;
        if (l < r) {
            int mid = (l + r) >> 1;
            ++num; segt[curpos].lc = num;
            ++num; segt[curpos].rc = num;
            build(segt[curpos].lc, l, mid);
            build(segt[curpos].rc, mid + 1, r);
        }
    }

    void maintain(Node &fa, Node &lhs, Node &rhs) {
        fa.val = lhs.val + rhs.val;
    }

    void addPoint(int pos, int val) {
        totVer++;
        ver[totVer] = update(pos, val, ver[totVer - 1]);
    }

    int update(int curpos, int pos, int val) {
        int t = num++;
        segt[t] = segt[curpos];
        if (segt[t].l == segt[t].r)
            segt[t].val += val;
        else {
            int mid = segt[curpos].l + segt[curpos].r >> 1;
            if (pos <= mid) segt[t].lc = update(segt[t].lc, pos, val);
            else segt[t].rc = update(segt[t].rc, pos, val);
            maintain(segt[t], segt[segt[t].lc], segt[segt[t].rc]);
        }
        return t;
    }

    int query(int curpos1, int curpos2, int l, int r) {
        if (segt[curpos1].l == l && segt[curpos1].r == r)
            return segt[curpos2].val - segt[curpos1].val;
        int mid = segt[curpos1].l + segt[curpos1].r >> 1;
        if (r <= mid) return query(segt[curpos1].lc, segt[curpos2].lc, l, r);
        else if (l > mid) return query(segt[curpos1].rc, segt[curpos2].rc, l, r);
        else return query(segt[curpos1].lc, segt[curpos2].lc, l, mid) + query(segt[curpos1].rc, segt[curpos2].rc, mid + 1, r);
    }

} segt;

int main() {
    int caseNum;
    scanf("%d", &caseNum);
    while (caseNum--) {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]); b[i] = a[i];
        }
        sort(b, b + n);
        int _size = unique(b, b + n) - b;
        segt.buildTree(0, _size - 1);
        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(b, b + _size, a[i]) - b;
            segt.addPoint(pos, 1);
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            int l, r, p, k;
            scanf("%d%d%d%d", &l, &r, &p, &k);
            l ^= ans; r ^= ans; p ^= ans; k ^= ans;
            int _l = -1, _r = max(abs(p - b[0]), abs(p - b[_size - 1])) + 1;
            while (_l + 1 < _r) {
                int mid = _l + _r >> 1, s;
                int lInv = lower_bound(b, b + _size, p - mid) - b;
                int rInv = upper_bound(b, b + _size, p + mid) - b - 1;
                if (lInv <= rInv) s = segt.query(segt.ver[l - 1], segt.ver[r], lInv, rInv);
                else s = 0;
                if (s >= k) _r = mid;
                else _l = mid;
            }
            printf("%d\n", _r);
        }
    }
    return 0;
}
