#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n, m, ans = INT_MAX;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    for (int i = 1; i <= n - m + 1; i++)
    {
        // cout << "i = " << i << " i + m - 1 = " << i + m - 1 << " a[i+m-1]-a[i-1] = " << a[i + m - 1] - a[i - 1] << '\n';
        ans = min(ans, a[i + m - 1] - a[i - 1]);
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}