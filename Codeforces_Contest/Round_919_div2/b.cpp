#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k, x, ans = INT_MIN; cin >> n >> k >> x;
    vector<int>a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a.begin() + 1, a.end());
    reverse(a.begin() + 1, a.end());
    for (int i = 1;i <= n;i++) b[i] = b[i - 1] + a[i];
    for (int i = 0;i <= k;i++) {
        int total = b[n] - b[i];
        total -= 2 * (b[min(n, i + x)] - b[i]);
        ans = max(ans, total);
    }
    cout << ans << '\n';
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