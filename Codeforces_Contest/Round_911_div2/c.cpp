#include <bits/stdc++.h>

using namespace std;

vector<int> l, r;
string s;

void solve()
{
    int n;
    cin >> n;
    cin >> s;
    l.resize(n + 1, 0);
    r.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];

    function<int(int)> dfs = [&](int x) -> int
    {
        if (!l[x] && !r[x])
            return 0;
        int ans = INT_MAX;
        if (l[x])
            ans = min(ans, dfs(l[x]) + (s[x - 1] != 'L'));
        if (r[x])
            ans = min(ans, dfs(r[x]) + (s[x - 1] != 'R'));
        return ans;
    };

    cout << dfs(1) << '\n';
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