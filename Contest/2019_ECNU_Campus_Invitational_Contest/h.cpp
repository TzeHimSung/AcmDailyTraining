#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (a % b == 0) return b;
    else return gcd(b, a % b);
}

int main()
{
    ll h, m;
    cin >> h >> m;
    if (h <= m)
    {
        ll x1 = h;
        ll x2 = 2ll * m - h + 1;
        ll a = x1 * x2 / 2ll;
        ll b = h * m;
        ll g = gcd(a, b);
        a /= g; b /= g;
        cout << a << '/' << b << endl;
    }
    else
    {
        ll a = m * (m + 1) / 2ll;
        ll b = h * m;
        ll g = gcd(a, b);
        a /= g; b /= g;
        cout << a << '/' << b << endl;
    }

    return 0;
}