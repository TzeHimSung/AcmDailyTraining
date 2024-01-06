#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, a, t = 0;
    cin >> n;
    a = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < a; j++)
        {
            t++;
            cout << setw(2) << setfill('0') << t;
        }
        a--;
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}