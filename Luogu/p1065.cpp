#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve() {
    int n, m, ans = 0; cin >> m >> n;
    vector<int>num(410), calc(410), last(30);
    vector<vector<int>> whe(30, vector<int>(30));
    vector<vector<int>> tim(30, vector<int>(30));
    vector<vector<int>> vis(30, vector<int>(10001));
    for (int i = 1;i <= n * m;i++) cin >> num[i];
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> whe[i][j];
        }
    }
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> tim[i][j];
        }
    }
    for (int i = 1;i <= n * m;i++) {
        calc[num[i]]++;
        int p1 = num[i], p2 = calc[num[i]], w = whe[p1][p2], t = tim[p1][p2], res = 0, j = 0;
        for (j = last[p1] + 1;j <= 10000;j++) {
            if (vis[w][j]) res = 0; else res++;
            if (res == t) break;
        }
        int tmp = j;
        for (j = tmp - t + 1; j <= tmp;j++) vis[w][j] = 1;
        last[p1] = tmp;
        ans = max(ans, last[p1]);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}