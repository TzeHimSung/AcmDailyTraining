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
int n, m, a[maxn], ans[maxn];
struct SegmentTree {
    struct Node {
        int val, add;
    } mem[maxn << 2];
    SegmentTree() {}

    void build(int *a, int curpos, int curl, int curr) {
        if (curl == curr) {
            mem[curpos].val = a[curl];
            mem[curpos].add = 0;
            return;
        }
        int mid = curl + curr >> 1;
        build(a, lson, curl, mid); build(a, rson, mid + 1, curr);
    }

    void update(int curpos, int pos, int curl, int curr, int val) {
        if (curl == curr) {
            mem[curpos].val = val;
            mem[curpos].add = 0;
            return;
        }
        int mid = curl + curr >> 1;
        mem[lson].add = max(mem[curpos].add, mem[lson].add);
        mem[rson].add = max(mem[curpos].add, mem[rson].add);
        mem[curpos].add = 0;
        if (pos <= mid) update(lson, pos, curl, mid, val);
        else update(rson, pos, mid + 1, curr, val);
    }

    void maintain(int curpos, int curl, int curr) {
        if (curl == curr) {
            ans[curl] = max(mem[curpos].val, mem[curpos].add);
            return;
        }
        mem[lson].add = max(mem[lson].add, mem[curpos].add);
        mem[rson].add = max(mem[rson].add, mem[curpos].add);
        int mid = curl + curr >> 1;
        maintain(lson, curl, mid); maintain(rson, mid + 1, curr);
    }
} st;

int main() {
    scanf("%d", &n);
    rep1(i, 1, n) scanf("%d", &a[i]);
    st.build(a, 1, 1, n);
    scanf("%d", &m);
    while (m--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int pos, val; scanf("%d%d", &pos, &val);
            st.update(1, pos, 1, n, val);
        } else {
            int val; scanf("%d", &val);
            st.mem[1].add = max(st.mem[1].add, val);
        }
    }
    st.maintain(1, 1, n);
    rep1(i, 1, n) printf("%d ", ans[i]);
    return 0;
}