#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    vector<int> a = {0, 1, 0}, b = {0, 1, 1, 0};
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            cout << "1\n";
        else if (i == 2)
            cout << "1 1\n";
        else
        {
            a = b;
            b.resize(i + 1, 0);
            for (int j = 1; j <= i; j++)
                b[j] = a[j - 1] + a[j];
            b.emplace_back(0);
            for (int j = 1; j <= i; j++)
                cout << b[j] << ' ';
            cout << '\n';
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