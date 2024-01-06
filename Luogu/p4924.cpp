#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void init(int n, vector<vector<int>>& a) {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            a[i][j] = (i - 1) * n + j;
        }
    }
}

void go(int x, int y, int r, int z, vector<vector<int>>& a, vector<vector<int>>& b) {
    int sx = x - r, sy = y - r, tr = 2 * r + 1;
    for (int i = 1;i <= tr;i++) {
        for (int j = 1;j <= tr;j++) {
            b[i][j] = a[sx + i - 1][sy + j - 1];
        }
    }
    for (int i = 1;i <= tr;i++) {
        for (int j = 1;j <= tr;j++) {
            a[i + sx - 1][j + sy - 1] = (z ? b[j][tr - i + 1] : b[tr - j + 1][i]);
        }
    }
}

void print(int n, const vector<vector<int>>& a) {
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= n;j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

void solve() {
    int n, m;cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0)), b(n + 1, vector<int>(n + 1, 0));
    init(n, a);
    while (m--) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        go(x, y, r, z, a, b);
    }
    print(n, a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}