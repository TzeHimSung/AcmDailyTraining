#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int ans = 0;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < i;j++)
            if (a[j] > a[i]) ans++;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}