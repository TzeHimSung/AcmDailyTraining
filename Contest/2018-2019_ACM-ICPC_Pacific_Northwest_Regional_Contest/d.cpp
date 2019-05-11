#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
ll f[130][1110][130];
ll mod = 1000000009;

int main()
{
    ll Mod, bit;
    cin >> Mod >> bit;
    f[1][1 % Mod][1] = 1;
    for (int i = 1; i <= bit; i++)
    {
        for (int j = 0; j < Mod; j++)
        {
            for (int k = 0; k <= i; k++)
            {
                f[i + 1][(j * 2) % Mod][k] += f[i][j][k];
                f[i + 1][(j * 2 + 1) % Mod][k + 1] += f[i][j][k];
                f[i + 1][(j * 2) % Mod][k] %= mod;
                f[i + 1][(j * 2 + 1) % Mod][k + 1] %= mod;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= bit; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            ans += f[i][0][j] * j;
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}