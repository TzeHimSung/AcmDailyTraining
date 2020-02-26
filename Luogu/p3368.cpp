/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

class FenwickTree {
public:
    // 存储的信息类型
    typedef int StoreType;
    int n;
    vector<StoreType>num;

    FenwickTree(): n(0) {}
    FenwickTree(int _n) {
        n = _n;
        num.assign(n, 0);
    }
    // 单点修改
    void add(int pos, int val) {
        for (; pos < n; pos |= pos + 1) num[pos] += val;
    }
    // 查询区间[0..pos]的信息
    StoreType sum(int pos) {
        StoreType ret = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1) ret += num[pos];
        return ret;
    }
    // 查询区间[l..r]的和
    StoreType querySum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    // 区间修改，给区间[l..r]里的元素都加上val
    void intervalFix(int l, int r, int val) {
        add(l, val); add(r + 1, -val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, last = 0;
    cin >> n >> m;
    FenwickTree bit(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        bit.add(i, x - last);
        last = x;
    }
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int x, y, k; cin >> x >> y >> k;
            bit.intervalFix(x, y, k);
        } else {
            int x; cin >> x;
            cout << bit.sum(x) << endl;
        }
    }
    return 0;
}