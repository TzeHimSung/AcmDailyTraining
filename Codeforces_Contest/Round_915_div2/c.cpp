#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string sorted_s = s;
    sort(sorted_s.begin(), sorted_s.end());
    if (s == sorted_s)
    {
        cout << "0\n";
        return;
    }
    string k = "";
    vector<int> position;
    char last_char = ' ';
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1 || s[i] >= last_char)
        {
            k += s[i];
            position.emplace_back(i);
            last_char = s[i];
        }
    }
    int ans = k.size();
    for (int i = 0; i < k.size(); i++)
    {
        if (k[i] == k.back())
        {
            ans--;
        }
    }
    for (int i = position.size() - 1, j = 0; i >= 0; i--, j++)
    {
        s[position[i]] = k[j];
    }
    if (s == sorted_s)
    {
        cout << ans << '\n';
    }
    else
    {
        cout << "-1\n";
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
