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

struct FenwickTree {
    int n;
    vector<ll>num;
    FenwickTree(): n(0) {}
    FenwickTree(int _n) {
        n = _n;
        num.assign(n, 0);
    }
    void add(int i, int val) {
        for (; i < n; i |= i + 1) num[i] += val;
    }
    ll sum(int i) {
        ll ret = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) ret += num[i];
        return ret;
    }
};

int main() {
    int n; scanf("%d", &n);
    vector<pair<int, int>>point(n);
    vector<int>speed;
    for (int i = 0; i < n; i++) scanf("%d", &point[i].first);
    for (int i = 0; i < n; i++) {
        scanf("%d", &point[i].second);
        speed.push_back(point[i].second);
    }
    // 对速度离散化
    sort(speed.begin(), speed.end());
    speed.erase(unique(speed.begin(), speed.end()), speed.end());
    // 先按位置排序，再按速度排序
    sort(point.begin(), point.end());

    ll ans = 0;
    FenwickTree cnt(n), sumx(n);
    // 枚举每一个点
    for (auto i : point) {
        // 找到所有点j，满足Xj<Xi且Vj<=Vi
        int pos = lower_bound(speed.begin(), speed.end(), i.second) - speed.begin();
        ans += cnt.sum(pos) * i.first - sumx.sum(pos);
        // 记录出现次数和横坐标总和
        cnt.add(pos, 1);
        sumx.add(pos, i.first);
    }
    printf("%lld\n", ans);
    return 0;
}