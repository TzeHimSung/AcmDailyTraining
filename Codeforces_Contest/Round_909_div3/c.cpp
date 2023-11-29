#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, ans = INT_MIN, cur = INT_MIN, last;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!i)
            cur = max(cur, 0) + x;
        else
            cur = max((abs(x % 2) == abs(last % 2) ? 0 : cur), 0) + x;
        ans = max(ans, cur);
        last = x;
    }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}