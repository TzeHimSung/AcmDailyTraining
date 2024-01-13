#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m;cin >> n >> m;
    map<int, int>cnt;
    while (m--) {
        int x;cin >> x;
        cnt[x]++;
    }
    for (int i = 1;i <= n;i++) {
        if (cnt[i]) {
            while (cnt[i]--) cout << i << ' ';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}