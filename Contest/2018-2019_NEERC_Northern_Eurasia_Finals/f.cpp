#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll gcd(ll a, ll b)
{
    return (!b) ? a : gcd(b, a % b);
}

void exgcd(ll a, ll b, ll &x, ll&y)
{
    if(!b)
    {
        x = 1; y = 0;
    }
    else
    {
        exgcd(b, a % b, y, x);
        y -= x * (a / b);
    }
}

int main()
{
    ll n; cin >> n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ll a = i, b = n / i, g = gcd(a, b), x = 0, y = 0;
            if (g != 1) continue;
            if ((n - 1) % g) continue;
            exgcd(a, b, x, y);
            x = (x + b / g) * ((n - 1) / g); x = (x % (b / g) + b / g) % (b / g);
            y = (n - a * x - 1) / b;
            printf("YES\n2\n");
            printf("%lld %lld\n", x / gcd(b, x), b / gcd(b, x));
            printf("%lld %lld\n", y / gcd(y, a), a / gcd(y, a));
            return 0;
        }
    }
    puts("NO");
    return 0;
}
