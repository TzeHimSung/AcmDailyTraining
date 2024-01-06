#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    map<char, int> cnt;
    string s;
    cin >> s;
    for (auto i : s)
        cnt[i]++;
    int maxx = 0, minn = INT_MAX;
    for (auto i : cnt)
    {
        maxx = max(maxx, i.second);
        minn = min(minn, i.second);
    }
    int k = maxx - minn;
    if (k <= 1)
    {
        cout << "No Answer\n0\n";
        return;
    }
    for (int i = 2; i * i <= k; i++)
    {
        if (k % i)
            continue;
        else
        {
            cout << "No Answer\n0\n";
            return;
        }
    }
    cout << "Lucky Word\n"
         << k << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}