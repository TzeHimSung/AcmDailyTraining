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

const int maxn = 1e5 + 10;
ll n, k, lc, lm, pc, pm, t, d, a[maxn];

int main() {
    cin >> n >> k >> lc >> pc >> lm >> pm >> t >> d;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll ans = INT_MAX, need = 0, have = 0, cost = 0;
    int illegal = 0;
    for (int i = 1; i <= n; i++) {
        have += max(1LL, min(d, a[i] - lm));
        need += max(1LL, min(d, lm - a[i]));
        if (a[i] + d < lm) illegal++;
    }
    cost = pm * n + need * t;
    if (!illegal && have >= need) ans = cost;
    int s = 1, e = n;
    ll cnt = 0;
    while (e - s + 1 >= k) {
        cnt++;
        for (int i = 0; i < k - 1; i++) {
            need -= max(1LL, min(d, lm - a[i + s]));
            have += min(d, min(lm, a[i + s]) - 1);
            if (a[i + s] + d < lm)illegal--;
        }
        need += max(1LL, lc - max(lm, a[e]));
        have -= max(1LL, min(d, a[e] - lm));
        have += max(1LL, min(d, a[e] - lc));
        if (a[e] + d < lc) break;
        cost = pm * (n - cnt * k) + cnt * pc + need * t;
        if (!illegal && have >= need) ans = min(ans, cost);
        s += k - 1, e--;
    }
    if (a[e] + d >= lc) {
        cnt++;
        for (int i = 0; i < e - s; i++) {
            need -= max(1LL, min(d, lm - a[i + s]));
            have += min(d, min(lm, a[i + s]) - 1);
            if (a[i + s] + d < lm) illegal--;
        }
        need += max(1LL, lc - max(lm, a[e]));
        have -= max(1LL, min(d, a[e] - lm));
        have += max(1LL, min(d, a[e] - lc));
        cost = cnt * pc + need * t;
        if (!illegal && have >= need) ans = min(ans, cost);
    }
    if (ans == INT_MAX) puts("-1");
    else cout << ans << endl;
    return 0;
}