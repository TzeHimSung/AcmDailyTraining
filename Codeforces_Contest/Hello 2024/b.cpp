#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;cin >> n;
    string s;cin >> s;
    int ans = 0;
    for (int i = 0;i < n;i++) {
        if (s[i] == '+') ans++;
        else ans--;
    }
    cout << abs(ans) << '\n';
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