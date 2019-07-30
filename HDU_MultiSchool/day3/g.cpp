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
int t, n, ans[maxn];
ll m, sum[maxn * 5], cnt[maxn * 5];

struct SegmentTree {
    struct STNode {
        ll sum, cnt;
    } mem[maxn * 5];

    SegmentTree() {
        rep0(i, 0, maxn * 5) mem[i].cnt = mem[i].sum = 0;
    }

    int query(int curpos, int curl, int curr, ll val, ll tot) {
        if (mem[curpos].sum + tot <= val) return mem[curpos].cnt;
        int mid = curl + curr >> 1;
        int ret = query(lson, curl, mid, val, tot);
        if (ret == mem[lson].cnt)
            ret += query(rson, mid + 1, curr, val, tot + mem[lson].sum);
        return ret;
    }

    void insert(int curpos, int pos, int curl, int curr, ll val) {
        if (curl == curr) {
            mem[curpos].sum = val; mem[curpos].cnt = 1;
            return;
        }
        int mid = curl + curr >> 1;
        if (pos <= mid) insert(lson, pos, curl, mid, val);
        else insert(rson, pos, mid + 1, curr, val);
        mem[curpos].sum = mem[lson].sum + mem[rson].sum;
        mem[curpos].cnt = mem[lson].cnt + mem[rson].cnt;
    }

    void clear() {
        rep0(i, 0, maxn * 5) mem[i].cnt = mem[i].sum = 0;
    }
} st;

struct Node {
    ll val;
    int num, rank;
} a[maxn];

bool cmp(const Node &lhs, const Node &rhs) {
    return lhs.val < rhs.val;
}

bool cmp2(const Node &lhs, const Node &rhs) {
    return lhs.num < rhs.num;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        st.clear();
        rep0(i, 0, maxn) ans[i] = 0;
        scanf("%d%lld", &n, &m);
        rep1(i, 1, n) {
            scanf("%lld", &a[i].val);
            a[i].num = i;
        }
        sort(a + 1, a + 1 + n, cmp);
        rep1(i, 1, n) a[i].rank = i;
        sort(a + 1, a + 1 + n, cmp2);
        rep1(i, 1, n) {
            int t = st.query(1, 1, n, m - a[i].val, 0);
            ans[i] = i - 1 - t;
            st.insert(1, a[i].rank, 1, n, a[i].val);
        }
        rep1(i, 1, n) printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}