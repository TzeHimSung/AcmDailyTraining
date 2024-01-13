#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, r; cin >> n >> r;
    vector<int> a(n + 1);
    auto dfs = [&](auto self, int k) {
        if (k > r) {
            for (int i = 1;i <= r;i++) {
                cout << setw(3) << a[i];
            }
            cout << '\n';
            return;
        }
        for (int i = a[k - 1] + 1;i <= n;i++) {
            a[k] = i;
            self(self, k + 1);
        }
    };
    dfs(dfs, 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}