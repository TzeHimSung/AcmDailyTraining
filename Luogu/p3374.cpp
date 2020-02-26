#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Fenwick Tree, 又叫Binary Indexed Tree(BIT)，中文名称树状数组
// 依赖: vector
// 注意，下标从0开始，但不影响使用
class FenwickTree {
private:
    // 存储的信息类型
    typedef int StoreType;
    int n;
    vector<StoreType>num;
public:
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
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    FenwickTree bit(n + 1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        bit.add(i, x);
    }
    while (m--) {
        int op, x, y; cin >> op >> x >> y;
        if (op == 1) bit.add(x, y);
        else cout << bit.querySum(x, y) << endl;
    }
}