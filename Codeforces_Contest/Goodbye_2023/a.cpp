#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int remain = 2023;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (auto i : a)
    {
        if (remain % i)
        {
            cout << "NO\n";
            return;
        }
        remain /= i;
    }
    cout << "YES\n";
    for (int i = 1; i <= k - 1; i++)
        cout << "1 ";
    cout << remain << '\n';
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