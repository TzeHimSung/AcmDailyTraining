#include <bits/stdc++.h>

using namespace std;

void solve()
{
    const int maxn = 20 + 2;
    int w, x, h;
    cin >> w >> x >> h;
    int a[maxn][maxn][maxn];
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= h; k++)
            {
                a[i][j][k] = 1;
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x1, x2, y1, y2, z1, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                for (int k = z1; k <= z2; k++)
                {
                    a[i][j][k] = 0;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= w; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            for (int k = 1; k <= h; k++)
            {
                if (a[i][j][k])
                    ans++;
            }
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