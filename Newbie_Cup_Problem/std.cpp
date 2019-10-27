#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define ll long long

using namespace std;

int n;
vector<pair<ll, ll>> v;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b) {
    return atan2(a.second, a.first) < atan2(b.second, b.first);
}

int main() {
    // freopen("./Newbie_Cup_Problem/data/5.in", "r", stdin);
    // freopen("./Newbie_Cup_Problem/data/5.out", "w", stdout);
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        v.clear();
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
        printf("%lld\n", (ll)floor(sqrt(ans)));
    }
    // fclose(stdin);
    // fclose(stdout);
    return 0;
}