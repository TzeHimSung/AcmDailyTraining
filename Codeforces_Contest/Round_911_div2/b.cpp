#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];
    for (int i = 0; i < 3; i++)
        cout << (a[i] % 2 == (a[0] + a[1] + a[2]) % 2) << ' ';
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