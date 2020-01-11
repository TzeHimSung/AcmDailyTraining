#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
#define ff first
#define ss second

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

ll a[1010];
int main() {
    int n; ll m;
    while (~scanf("%d%lld", &n, &m)) {
        for (int i = 1; i <= n; i++)scanf("%lld", &a[i]);
        pii cur = make_pair(1, a[1]);
        for (int i = 2; i <= n; i++) {
            ll x = lcm(cur.ss, a[i]);
            cur.ff = cur.ff * (x / cur.ss) + x / a[i];
            cur.ss = x;
            ll g = __gcd(cur.ff, cur.ss);
            cur.ff /= g, cur.ss /= g;
        }
        if (m % cur.ff) {
            printf("No\n"); continue;
        }
        ll x = m / cur.ff * cur.ss;
        ll lcmm = 1;
        for (int i = 1; i <= n; i++)lcmm = lcm(lcmm, a[i]);
        if (x % lcmm) {
            printf("No\n"); continue;
        } else {
            printf("Yes\n");
            printf("%lld", x / a[1]);
            for (int i = 2; i <= n; i++)printf(" %lld", x / a[i]);
            printf("\n");
        }
    }
}