#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, int> pii;
#define ff first
#define ss second
#define mp make_pair

pii p[100010];
int check(double x, int n) {
    int cur = 1;
    while (cur <= n) {
        ll add = 0;
        while (p[cur].ff - x <= 0)
            add += p[cur++].ss;
        if (add == 0)
            return 0;
        x += add;
    }
    return 1;
}
int main() {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    for (int i = 1; i <= n; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        p[i] = mp(sqrt(1ll * (u - x) * (u - x) + 1ll * (v - y) * (v - y)) - w, w);
    }
    sort(p + 1, p + 1 + n);

    double l = max(0.0, p[1].ff), r = p[n].ff, eps = 1e-8;
    double ans = r;
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        if (check(mid, n)) {
            r = mid;
            ans = min(ans, mid);
        } else
            l = mid;
    }
    printf("%.10lf\n", ans);
}