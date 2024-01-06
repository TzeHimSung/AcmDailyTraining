#include <bits/stdc++.h>

using namespace std;

void solve()
{
    const int maxn = 50;
    int a[maxn][maxn];
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j <= maxn; j++)
            a[i][j] = 0;
    int n;
    cin >> n;
    int last_x = 1, last_y = n / 2 + 1, curr = 1;
    a[last_x][last_y] = curr;
    while (curr <= n * n)
    {
        curr++;
        if (last_x == 1 && last_y != n)
        {
            last_x = n;
            last_y++;
        }
        else if (last_y == n && last_x != 1)
        {
            last_x--;
            last_y = 1;
        }
        else if (last_x == 1 && last_y == n)
        {
            last_x++;
        }
        else
        {
            if (!a[last_x - 1][last_y + 1])
            {
                last_x--;
                last_y++;
            }
            else
            {
                last_x++;
            }
        }
        a[last_x][last_y] = curr;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i][1];
        for (int j = 2; j <= n; j++)
            cout << ' ' << a[i][j];
        cout << '\n';
    }
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}