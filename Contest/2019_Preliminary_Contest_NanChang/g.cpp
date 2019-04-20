#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <assert.h>
typedef long long ll;
using namespace std;

const int N = 1e7 + 10;
const ll MOD = (1 << 30);

int pri[N / 10];
int phi[N];
short mu[N];
bool vis[N];
ll f[N];

ll pw3(ll n)
{
    return n * n % MOD * n % MOD;
}

ll S(ll n, int k)
{
    if (k == 0) return n;
    else if (k == 1) return (1LL * n * (n + 1) / 2) % MOD;
    else
    {
        ll ans = 1LL * n * (n + 1) / 2;
        if (ans % 3 == 0) return (ans / 3) % MOD * (2 * n + 1) % MOD;
        else return ((2LL * n + 1) / 3) * (ans % MOD) % MOD;
    }
}

ll S(ll n)
{
    return 1LL * S(n, 0) * S(n, 1) % MOD * S(n, 2) % MOD;
}

ll calans(int n)
{
    ll ans = 0;
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = n / (n / l);
        ans += (f[r] - f[l - 1]) * S(n / l);
        ans %= MOD;
    }
    if (ans < 0) ans += MOD;
    return ans;
}

void init()
{

    int cnt = 0;
    phi[1] = 1; mu[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (!vis[i])
        {
            phi[i] = i - 1, pri[++cnt] = i, mu[i] = -1;
        }
        for (int j = 1; j <= cnt; j++)
        {
            int u = pri[j] * i;
            if (u >= N) break;
            vis[u] = 1;
            if (i % pri[j] == 0)
            {
                phi[u] = phi[i] * pri[j];
                mu[u] = 0;
                break;
            }
            phi[u] = phi[i] * (pri[j] - 1);
            mu[u] = -mu[i];
        }
    }
    for (int i = 1; i < N; i++)
    {
        if (mu[i] == 0) continue;
        for (int j = 1; i * j < N; j++)
        {
            f[i * j] += 1LL * phi[j] * mu[i];
        }
    }
    for (int i = 1; i < N; i++) f[i] = (f[i] % MOD * pw3(i) + f[i - 1]) % MOD;
}

#include <time.h>
int main()
{

    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    //time_t s=clock();
    init();

    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        printf("%lld\n", calans(n));
    }
    /*
    time_t t=clock();
    cerr<<(t-s)/1000.0<<endl;
    */

    return 0;
}