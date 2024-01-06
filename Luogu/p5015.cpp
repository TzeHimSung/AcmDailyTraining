#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string x;
            cin >> x;
            s += x;
            cout << s << '\n';
        }
        else if (op == 2)
        {
            int index, len;
            cin >> index >> len;
            s = s.substr(index, len);
            cout << s << '\n';
        }
        else if (op == 3)
        {
            int index;
            string x;
            cin >> index >> x;
            s.insert(index, x);
            cout << s << '\n';
        }
        else
        {
            string x;
            cin >> x;
            cout << (int(s.find(x)) < int(s.size()) ? int(s.find(x)) : -1) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}