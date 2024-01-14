#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int greater = -1, less = INT_MAX;
    set<int>not_equal;
    int n; cin >> n;
    while (n--) {
        int op, x; cin >> op >> x;
        if (op == 1) {
            greater = max(greater, x);
        } else if (op == 2) {
            less = min(less, x);
        } else {
            not_equal.insert(x);
        }
    }
    if (greater > less) {
        cout << "0\n";
        return;
    }
    int ans = less - greater + 1;
    for (auto i : not_equal) {
        if (greater <= i && i <= less) {
            ans--;
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