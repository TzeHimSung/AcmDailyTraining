#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

int n;
vector<pair<ll, ll>> v;

bool cmp(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return atan2(a.second, a.first) < atan2(b.second, b.first);
}

int main() {
    freopen("./Newbie_Cup_Problem/data/6.in", "r", stdin);
    freopen("./Newbie_Cup_Problem/data/6.out", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        pair<ll, ll> p; scanf("%lld%lld", &p.first, &p.second);
        if (p.first || p.second) v.push_back(p);
    }
    n = (int)v.size();
    // sort by slope
    sort(v.begin(), v.end(), cmp);
    ll ans = 0;
    // enumerate each vector as start
    for (int i = 0; i < n; i++) {
        int j = i; ll x = 0, y = 0;
        for (int k = 0; k < n; k++) {
            // just pick all vector and maintain ans directly
            x += v[j].first; y += v[j].second;
            ans = max(ans, x * x + y * y);
            if (++j == n) j = 0;
        }
    }
    printf("%d\n", (int)floor(sqrt(ans)));

    fclose(stdin);
    fclose(stdout);
    return 0;
}