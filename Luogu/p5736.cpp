#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAXN = 1e5 + 10;
bitset<MAXN>p;

void getPrime(int n) {
    p.set();
    p[0] = p[1] = 0;
    for (int i = 2;i * i <= n;i++) {
        if (p[i]) {
            for (int j = i << 1;j <= n;j += i) p[j] = 0;
        }
    }
}

void solve() {
    int n; cin >> n;
    vector<int>a;
    for (int i = 0;i < n;i++) {
        int x; cin >> x;
        if (p[x]) a.emplace_back(x);
    }
    for (auto i : a) cout << i << ' ';
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    getPrime(MAXN - 10);
    solve();

    return 0;
}