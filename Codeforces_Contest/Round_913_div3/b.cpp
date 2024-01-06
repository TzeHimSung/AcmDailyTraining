#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> l, u;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'b')
        {
            if (!l.empty())
            {
                l.pop_back();
            }
        }
        else if (s[i] == 'B')
        {
            if (!u.empty())
            {
                u.pop_back();
            }
        }
        else if (isupper(s[i]))
        {
            u.push_back(i);
        }
        else
        {
            l.push_back(i);
        }
    }

    int i = 0, j = 0;

    while (i < l.size() || j < u.size())
    {
        if (i < l.size() && (j == u.size() || l[i] < u[j]))
        {
            cout << s[l[i++]];
        }
        else
        {
            cout << s[u[j++]];
        }
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