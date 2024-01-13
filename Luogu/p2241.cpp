#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    ll n, m, sqr = 0, rec = 0;
    cin >> n >> m;
    for (ll i = 0;i < n;i++) {
        for (ll j = 0;j < m;j++) {
            if (i == j) sqr += (n - i) * (m - j);
            else rec += (n - i) * (m - j);
        }
    }
    cout << sqr << ' ' << rec << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}