#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll inf = 1e18;

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<int>> app(1);
    vector<int> mul{ 1 };
    vector<ll> len{ 0 };

    while (n--) {
        int op, x; cin >> op >> x;
        if (op == 1) {
            // app是新加入数字的快照
            app.back().push_back(x);
        } else {
            // len.back()是上一份快照的长度
            // 如果上一份快照的长度已经超出查询范围，不再维护后面的复制
            if (len.back() < inf) {
                // mul.back()是上一份快照的总份数
                // len.back() * mul.back()意为上一份快照的总长度
                if (len.back() <= inf / mul.back()) {
                    // len更新了上一次快照的长度 * 份数 + 新快照的长度
                    len.push_back(len.back() * mul.back() + app.back().size());
                } else {
                    // 不维护了
                    len.push_back(inf);
                }
                // mul是当前快照的总份数
                mul.push_back(x + 1);
                // 复制完之后，app新建立一个快照，存放后面新加入的数字
                app.push_back({});
            }
        }
    }
    while (q--) {
        ll k; cin >> k;
        k--;
        // 对于每次查询，倒序遍历所有快照
        for (int i = app.size() - 1;i >= 0;i--) {
            // 当k < len[i] * mul[i]，说明要查询的数字还在前面，没有落在当前新数字快照
            if (k / mul[i] >= len[i]) {
                // 要查询的数字就是当前新数字快照下，查询位置 - 前一份快照的总长度
                cout << app[i][k - mul[i] * len[i]] << ' ';
                if (!q) {
                    cout << '\n';
                }
                break;
            } else {
                // 没有落在当前新数字快照时，k = mul[i] * len[i] + 新k
                // 故 k = k % len[i](或mul[i]);
                k %= len[i];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}