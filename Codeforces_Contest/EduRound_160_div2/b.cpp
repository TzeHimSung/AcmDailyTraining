#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    map<char, int> cnt, cur_cnt;
    for (auto i : s)
        cnt[i]++;
    int ans = 0;
    for (auto i : s)
    {
        cur_cnt[i]++;
        if (cnt['0'] >= cur_cnt['1'] && cnt['1'] >= cur_cnt['0'])
            ans++;
        else
            break;
    }
    cout << (int)s.size() - ans << '\n';
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