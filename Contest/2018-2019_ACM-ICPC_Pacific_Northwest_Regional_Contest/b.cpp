#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 10010000;

int N[maxn];
int p[maxn];
int mu[maxn];
int cnt;
void sha()
{
    N[1] = 1;
    mu[1] = 1;
    for (int i = 2; i < maxn; i++)
    {
        if (!N[i])
        {
            p[++cnt] = i;
            mu[i] = -1;
        }
        for (int j = 1; j <= cnt; j++)
        {
            if (i * p[j] >= maxn) break;
            N[i * p[j]] = 1;
            if (i % p[j] == 0)
            {
                mu[i * p[j]] = 0;
                break;
            }
            else
            {
                mu[i * p[j]] = -mu[i];
            }
        }
    }
}

int sum[maxn];
typedef long long ll;

ll cal(ll n, ll m)
{
    long long ans = 0;
    if (n > m) swap(n, m);
    for (int i = 1, la = 0; i <= n; i = la + 1)
    {
        la = min(m / (m / i), n / (n / i));
        ans += (sum[la] - sum[i - 1]) * (n / i) * (m / i);
    }
    return ans;
}

int main()
{
    sha();
    ll a, b, x, y;
    cin >> a >> b >> x >> y;
    for (int i = 1; i < maxn; i++)
    {
        sum[i] = sum[i - 1]  + mu[i];
    }
    ll ans = cal(b, y) - cal(a - 1, y) - cal(b, x - 1) + cal(a - 1, x - 1);
    cout << ans << endl;
    return 0;
}