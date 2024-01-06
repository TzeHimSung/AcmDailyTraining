#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    i64 sum = 0;
    int odd = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        odd += x % 2;
        int res = 0;
        if (odd == 1 && i == 1)
        {
            res = 0;
        }
        else
        {
            res = odd / 3 + (odd % 3 == 1 ? 1 : 0);
        }
        cout << sum - res << ' ';
    }
    cout << '\n';
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