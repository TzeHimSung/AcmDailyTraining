#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    array<int, 26> m{};
    for (auto i : s)
        m[i - 'a']++;
    cout << n - 2 * min(n / 2, n - *max_element(m.begin(), m.end())) << '\n';
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