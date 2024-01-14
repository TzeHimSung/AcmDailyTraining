#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, r, ans = 0; cin >> n >> m >> r;
    vector<string>a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector<int> dx{ 0,1 }, dy{ 1,0 };

    auto dfs = [&](auto self, int x, int y, int dir, int cur_length) {
        if (cur_length > r) {
            ans++;
            return;
        }
        if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] != '.')
            return;
        self(self, x + dx[dir], y + dy[dir], dir, cur_length + 1);
        return;
    };

    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
            if (a[i][j] == '.')
                for (int k = 0;k < 2;k++)
                    dfs(dfs, i, j, k, 1);
    if (r == 1) ans /= 2;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}