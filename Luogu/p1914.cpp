#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        s[i] = char((int(s[i]) - 97 + n) % 26 + 97);
    }
    cout << s << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}