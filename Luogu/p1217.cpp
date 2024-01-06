#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e9 + 10;
bitset<maxn> vis;

void getPrime(int n)
{
    vis.set();
    vis[0] = vis[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (vis[i])
        {
            for (int j = i << 1; j <= n; j += i)
                vis[j] = 0;
        }
    }
}

bool check(int num)
{
    int tmp = num, rev = 0;
    while (tmp)
    {
        rev = rev * 10 + tmp % 10;
        tmp /= 10;
    }
    return rev == num;
}

void solve()
{
    int a, b;
    cin >> a >> b;
    if (b >= 1e7)
        b = 1e7 - 1;
    getPrime(b);
    if (a > b)
        return;
    if (a % 2 == 0)
        a++;
    for (int i = a; i <= b; i += 2)
    {
        if (vis[i] && check(i))
            cout << i << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}