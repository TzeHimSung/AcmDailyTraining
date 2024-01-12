#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    int x = INT_MAX, y = INT_MAX, ans = 0;
    while (n--) {
        int a; cin >> a;
        if (x > y) {
            swap(x, y);
        }
        if (a <= x) {
            x = a;
        }
        else if (a <= y) {
            y = a;
        }
        else {
            x = a;
            ans++;
        }
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