#include <bits/stdc++.h>
using namespace std;
int T[200001];
set<pair<int, int>> Set[200001];
int s[200001];
int b[200001];
struct query {
    int id, val;
    query() {}
    query(int _id, int _val) {
        id = _id;
        val = _val;
    }
    bool operator< (const query &b) const {
        return val < b.val;
    }
};
query q[200001];
int lowbit(int x) {
    return x & (-x);
}
struct tree_array {
    int n, st;
    int a[200001];
    inline void setRange(int N) {
        n = N;
        st = 1;
        while ((st << 1) <= n) st <<= 1;
    }
    inline void clear() {
        memset(a, 0, sizeof(a));
    }
    inline void add(int pos, int val) {
        for (int i = pos; i <= n; i += lowbit(i)) a[i] += val;
    }
    inline int query(int pos) {
        int rnt = 0;
        for (int i = pos; i > 0; i -= lowbit(i)) rnt += a[i];
        return rnt;
    }
};
tree_array tr;
int ans[200001];
int main() {
    int n, m, Q;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &T[i]);

    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &s[i], &b[i]);
    }
    s[m] = INT_MAX;
    for (int i = 0; i < m; ++i) {
        Set[b[i]].insert(make_pair(s[i], s[i + 1] - 1));
    }
    scanf("%d", &Q);
    for (int i = 1; i <= Q; ++i) {
        int x;
        scanf("%d", &x);
        q[i] = query(i, -x);
    }
    sort(q + 1, q + Q + 1);
    tr.setRange(Q);
    //for (int i=1;i<=Q;++i) cout<<q[i].val<<" ";
    //cout<<endl;
    for (int i = 1; i <= n; ++i) {
        for (auto seg : Set[i]) {
            int l = seg.first - T[i - 1];
            int r = seg.second - T[i - 1];
            //cout<<"[debug] "<<i<<' '<<l<<" "<<r<<endl;
            int l1 = lower_bound(q + 1, q + Q + 1, query(0, l)) - q;
            int r1 = upper_bound(q + 1, q + Q + 1, query(0, r)) - q;
            if (l1 < r1) {
                if (l1 <= Q && l1 > 0) tr.add(l1, 1);
                if (r1 <= Q && r1 > 0) tr.add(r1, -1);
            }
        }
    }
    for (int i = 1; i <= Q; ++i) {
        ans[q[i].id] = tr.query(i);
    }
    for (int i = 1; i <= Q; ++i) printf("%d ", ans[i]);
}