#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    string s;
    getline(cin, s);
    vector<int> num{1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
    int ans = 0;
    for (auto i : s)
    {
        if ('a' <= i && i <= 'z')
            ans += num[i - 'a'];
        if (i == ' ')
            ans++;
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