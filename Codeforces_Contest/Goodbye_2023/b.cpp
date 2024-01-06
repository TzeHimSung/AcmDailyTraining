#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (b % a == 0)
    {
        cout << (i64)b * (b / a) << '\n';
    }
    else
    {
        cout << lcm(a, b) << '\n';
    }
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