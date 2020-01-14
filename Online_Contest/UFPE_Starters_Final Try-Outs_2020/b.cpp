#include <bits/stdc++.h>
using namespace std;
struct Segment_Tree {
    //constants and innerclass
    struct node {
        int l, r, lc, rc;
        long long val;
    };
    static const int N = 500000;
    static const int root = 0;

    //variables
    int num;
    node tr[2 * N];

    //methods
    void setRange(int l, int r, int now = root) {
        num = 0;
        build(l, r, now);
    }
    void build(int l, int r, int now) {
        tr[now].l = l; tr[now].r = r; tr[now].val = 0;
        if (l < r) {
            int mid = (l + r) >> 1;
            ++num; tr[now].lc = num;
            ++num; tr[now].rc = num;
            build(l, mid, tr[now].lc);
            build(mid + 1, r, tr[now].rc);
        }
    }

    void pushup(node &f, node &lc, node &rc) {
        f.val = lc.val + rc.val;
    }

    //warning: don't invoke both update and updateR in single segment tree, it may cause error
    void update(int pos, long long val, int now = root) {
        int mid = (tr[now].l + tr[now].r) >> 1;
        if (tr[now].l == tr[now].r) {
            tr[now].val = val;
            return;
        } else if (pos <= mid) update(pos, val, tr[now].lc);
        else update(pos, val, tr[now].rc);
        //write parent update here
        pushup(tr[now], tr[tr[now].lc], tr[tr[now].rc]);
    }

    long long query(int l, int r, int now = root) {
        if (tr[now].l == l && tr[now].r == r) return tr[now].val;
        else {
            //if (tr[now].cover!=0) pushdown(tr[now],tr[tr[now].lc],tr[tr[now].rc]);
            int mid = (tr[now].l + tr[now].r) >> 1;
            if (r <= mid) return query(l, r, tr[now].lc);
            else if (l > mid) return query(l, r, tr[now].rc);
            else return query(l, mid, tr[now].lc) + query(mid + 1, r, tr[now].rc);
        }
    }

};
Segment_Tree tr;
map<string, long long> Map;
string str[1000001];
char ch[10001];
int main() {
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", ch);
        str[i] = ch;
    }
    for (int i = 0; i < m; ++i) {
        long long v;
        scanf("%s%lld", ch, &v);
        Map[string(ch)] = v;
    }
    tr.setRange(1, n);
    for (int i = 1; i <= n; ++i) {
        tr.update(i, Map[str[i]]);
    }
    while (q--) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x;
            scanf("%d%s", &x, ch);
            tr.update(x, Map[string(ch)]);
        } else {
            int l, r;
            scanf("%d%d", &l, &r);
            long long s = tr.query(l, r);
            if (s <= 30 * (r - l + 1)) printf("NO\n");
            else printf("YES\n");
        }
    }
}