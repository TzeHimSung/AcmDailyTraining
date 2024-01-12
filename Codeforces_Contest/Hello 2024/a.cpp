#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int a, b;cin >> a >> b;
    if ((a + b) % 2) cout << "Alice\n";
    else cout << "Bob\n";
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