/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const ll inf = 1LL << 60;
ll n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    vector<ll>a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll u = inf, d = -inf;
    while (d + 1 < u) {
        ll m = u + d >> 1, c = 0;
        for (int i = 0; i < n; i++) {
            if (a[i]*a[i] <= m) c--;
            if (a[i] < 0) {
                ll mn = (m / a[i]) - 5;
                while (mn * a[i] > m) mn++;
                ll pos = lower_bound(a.begin(), a.end(), mn) - a.begin();
                c += n - pos;
            } else if (a[i] > 0) {
                ll mx = (m / a[i]) + 5;
                while (mx * a[i] > m) mx--;
                ll pos = upper_bound(a.begin(), a.end(), mx) - a.begin();
                c += pos;
            } else {
                if (m >= 0) c += n;
            }
        }
        c /= 2;
        if (c >= k) u = m; else d = m;
    }
    cout << u << endl;
    return 0;
}