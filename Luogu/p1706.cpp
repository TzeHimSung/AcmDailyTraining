#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, k = 1; cin >> n;
    vector<int>a(n + 1);
    for (int i = 1;i <= n;i++) a[i] = i, k *= i;
    for (int i = 1;i <= k;i++) {
        for (int j = 1;j <= n;j++) cout << setw(5) << a[j];
        cout << '\n';
        next_permutation(a.begin() + 1, a.end());
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}