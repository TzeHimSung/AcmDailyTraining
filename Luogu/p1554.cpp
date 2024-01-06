#include <bits/stdc++.h>

using namespace std;

void solve()
{
    vector<int>cnt(10);
    int n, m;
    cin >> n >> m;
    for (int i = n; i <= m; i++)
        for (int curr = i; curr; curr /= 10)
            cnt[curr % 10]++;
    for (int i = 0; i <= 9; i++)
        cout << cnt[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}