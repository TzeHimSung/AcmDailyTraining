#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    if (abs(a-b) % 10 == 0) {
        cout << abs(a-b) / 10 << '\n';
    } else {
        cout << abs(a-b) / 10 + 1 << '\n';
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