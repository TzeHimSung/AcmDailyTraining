#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n;cin >> n;
    n = (1 << n);
    vector<vector<int>> a(n + 2, vector<int>(n + 2, 0));
    a[0][n + 1] = 1;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            a[i][j] = a[i - 1][j] ^ a[i - 1][j + 1];
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}