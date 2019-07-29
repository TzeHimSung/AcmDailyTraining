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
struct SegmentTree {
    struct Node {
        int num, sum;
        Node() {
            num = 0, sum = 0;
        }
    } mem[maxn << 2];

    SegmentTree(int *a, int n) {
        build(a, 1, 1, n);
    }

    void maintain(int curpos) {
        mem[curpos].num = mem[lson].num + mem[rson].num;
        mem[curpos].sum = mem[lson].sum + mem[rson].sum;
    }

    void build(int *a, int curpos, int curl, int curr) {
        if (curl == curr) {
            mem[curpos].num = 1;
            mem[curpos].sum = a[curl];
            return;
        }
        int mid = curl + curr >> 1;
        build(a, lson, curl, mid); build(a, rson, mid + 1, curr);
        maintain(curpos);
    }

    Node query(int curpos, int curl, int curr, int ql, int qr) {
        if (ql <= curl && curr <= qr)
            return mem[curpos];
        int mid = curl + curr >> 1;
        if (qr <= mid) return query(lson, curl, mid, ql, qr);
        if (ql > mid) return query(rson, mid + 1, curr, ql, qr);
        Node ret;

    }
};

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m, a[maxn], len;
        scanf("%d%d", &n, &m);
        sot(a, n);
        len = unique(a + 1, a + 1 + n) - a - 1;
        SegmentTree seg = SegmentTree(a, len);

    }
    return 0;
}