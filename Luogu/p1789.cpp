#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n + 1, vector<int>(n + 1, 0));
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = max(1, y - 2); i <= min(n, y + 2); i++)
            a[x][i] = 1;
        for (int i = max(1, x - 2); i <= min(n, x + 2); i++)
            a[i][y] = 1;
        a[max(1, x - 1)][max(1, y - 1)] = a[max(1, x - 1)][min(n, y + 1)] = a[min(n, x + 1)][max(1, y - 1)] = a[min(n, x + 1)][min(n, y + 1)] = 1;
    }
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        for (int i = max(1, x - 2); i <= min(n, x + 2); i++)
            for (int j = max(1, y - 2); j <= min(n, y + 2); j++)
                a[i][j] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!a[i][j])
                ans++;
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}