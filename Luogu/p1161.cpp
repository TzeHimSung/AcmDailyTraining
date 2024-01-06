#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve()
{
    int n;
    cin >> n;
    bitset<2000010> lamp;
    lamp.reset();
    while (n--)
    {
        double a;
        int t;
        cin >> a >> t;
        for (int i = 1; i <= t && a * i <= 2000000; i++)
        {
            int index = (int)floor(a * i);
            // cout << "index = " << index << '\n';
            lamp.flip(index);
        }
    }
    for (int i = 1;; i++)
    {
        if (lamp[i])
        {
            cout << i << '\n';
            break;
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