#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> w(n + 1), b(n + 1), r(n + 1);
    string s;
    auto check = [&](char ch) {
        int cnt = 0;
        for (int i = 0;i < m;i++)
            if (s[i] != ch) cnt++;
        return cnt;
    };

    for (int i = 1;i <= n;i++) {
        cin >> s;
        w[i] = w[i - 1] + check('W');
        b[i] = b[i - 1] + check('B');
        r[i] = r[i - 1] + check('R');
    }
    int ans = INT_MAX;
    for (int i = 1;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            ans = min(ans, w[i] + b[j] - b[i] + r[n] - r[j]);
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}