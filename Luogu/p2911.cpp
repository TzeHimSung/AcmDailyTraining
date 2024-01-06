#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    map<int, int> cnt;
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                cnt[i + j + k]++;
            }
        }
    }
    int ans = 0, cur_cnt = 0;
    for (auto item : cnt)
    {
        if (item.second > cur_cnt)
        {
            cur_cnt = item.second;
            ans = item.first;
        }
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