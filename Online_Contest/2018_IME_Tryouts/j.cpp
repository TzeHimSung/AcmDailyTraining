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
private:
    // 存储的信息类型
    typedef int StoreType;
    int n;
    // num用于存储元素值，用于实现单点修改、区间查询
    // diff用于存储差分，用于实现区间修改
    vector<StoreType>num, diff;
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
    // 区间修改，给区间[l..r]里的元素都加上val
    void intervalFix(int l, int r, int val) {
        add(l, val); add(r + 1, -val);
    }
};

const int MAXN = 1e5 + 10;
int n, a[MAXN];
FenwickTree fwt(MAXN * 10);

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i]++;
        printf("%d\n", n - (i - fwt.sum(a[i] - 1)) + 1);
        fwt.add(a[i], 1);
    }
    return 0;
}