#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    vector<pair<double, double>>a(3);
    for (int i = 0;i < 3;i++) cin >> a[i].first >> a[i].second;
    double ans = sqrt(pow(a[0].first - a[1].first, 2) + pow(a[0].second - a[1].second, 2));
    ans += sqrt(pow(a[0].first - a[2].first, 2) + pow(a[0].second - a[2].second, 2));
    ans += sqrt(pow(a[2].first - a[1].first, 2) + pow(a[2].second - a[1].second, 2));
    cout << fixed << setprecision(2) << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}