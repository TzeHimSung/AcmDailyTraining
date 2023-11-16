#include <bits/stdc++.h>

using namespace std;

void solve()
{
    map<int, int> cnt, pos;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
        pos[x] = i;
    }
    for (auto i : cnt)
    {
        if (i.second == 1)
        {
            cout << pos[i.first] << '\n';
            return;
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