/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int n;
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
    return atan2(a.second, a.first) < atan2(b.second, b.first);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        pair<ll, ll> p; scanf("%lld%lld", &p.first, &p.second);
        if (p.first || p.second) v.pb(p);
    }
    n = (int)v.size();
    sort(v.begin(), v.end(), cmp);
    ll ans = 0;
    for (int i = 0; i < n; i++) { // enum each vector
        int j = i; ll x = 0, y = 0;
        for (int k = 0; k < n; k++) {
            x += v[j].first; y += v[j].second; // just pick all vector and maintain ans directly
            ans = max(ans, x * x + y * y);
            if (++j == n) j = 0;
        }
    }
    printf("%.15f\n", sqrt(ans));
    return 0;
}

