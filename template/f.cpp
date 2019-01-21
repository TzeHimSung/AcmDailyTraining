#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 2e5 + 10;
const double PI = acos(-1.0);
typedef long long ll;
ll gcd(ll x, ll y)
{
    return y == 0 ? x : gcd(y, x % y);
}
void exgcd(ll a, ll b, ll &x, ll&y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
    }
    else
    {
        exgcd(b, a % b, y, x);
        y -= x * (a / b);
    }
}
int main()
{
    ll n;
    cin >> n;
    for(ll i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            ll a = i;
            ll b = n / i;
            ll g = gcd(a, b);
            if((n - 1) % g)continue;
            ll x, y;
            exgcd(a, b, x, y);
            x = (x + b / g) * ((n - 1) / g);
            x = (x % (b / g) + b / g) % (b / g);
            y = (n - 1 - a * x) / b;
            printf("YES\n2\n");
            printf("%lld %lld\n", x / gcd(x, b), b / gcd(x, b));
            printf("%lld %lld\n", y / gcd(y, a), a / gcd(y, a));
            return 0;
        }
    }
    puts("NO");
    return 0;
}