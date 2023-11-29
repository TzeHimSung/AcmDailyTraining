#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int curr = 0, ans = 0, flag = 0;
    while (n--)
    {
        char ch;
        cin >> ch;
        if (ch == '.')
        {
            curr++;
            ans++;
            if (curr >= 3)
                flag = 1;
        }
        else
        {
            curr = 0;
        }
    }
    if (flag)
        cout << "2\n";
    else
        cout << ans << '\n';
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