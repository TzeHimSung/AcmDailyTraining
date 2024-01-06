#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, ans = 0;
    cin >> n;
    map<int, int> cnt;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        cnt[x]++;
        cnt[y]++;
    }
    for (auto i : cnt)
    {
        if (i.second == 1)
            ans++;
    }
    cout << (ans + 1) / 2 << endl;
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