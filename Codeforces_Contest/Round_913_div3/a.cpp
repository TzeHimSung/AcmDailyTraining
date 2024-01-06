#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    for (char i = 'a'; i <= 'h'; i++)
    {
        for (char j = '1'; j <= '8'; j++)
        {
            if ((s[0] == i) ^ (s[1] == j))
            {
                cout << i << j << '\n';
            }
        }
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