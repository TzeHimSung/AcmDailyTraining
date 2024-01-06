#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    set<int> num, res;
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        num.insert(a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            auto it = num.find(a[i] + a[j]);
            if (it != num.end())
            {
                res.insert(*it);
            }
        }
    }
    cout << res.size() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}