#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, score = 0; cin >> n;
    vector<int>a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int len = 1;len <= n;len++) {
        if (n % len) continue;
        int part = n / len, g = 0;
        for (int j = 0;j + part < n;j++) {
            g = gcd(g, a[j + part] - a[j]);
        }
        score += (g != 1);
    }
    cout << score << '\n';
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