#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<ll, ll> pii;

ll a[300010], ans[300010];
pii p[100010];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= 3 * n; i++)
            a[i] = ans[i] = 0;
        for (int i = 1; i <= m; i++)
            scanf("%lld", &p[i].ff), p[i].ff += n - 1;
        for (int i = 1; i <= m; i++)
            scanf("%lld", &p[i].ss);
        for (int i = 1; i <= m; i++) {
            int l = p[i].ff, r = p[i].ff + p[i].ss;
            if (l > r)
                swap(l, r);
            r++;
            a[l]++, a[r]--;
        }
        for (int i = 1; i < 3 * n; i++)
            a[i] += a[i - 1];
        for (int i = 0; i < 3 * n; i++)
            ans[i % n] += a[i];
        pii ansn = { 0, 0 };
        for (int i = 0; i < n; i++) {
            if (ans[i] > ansn.ff)
                ansn = { ans[i], i };
        }
        ansn.ss++;
        printf("%lld %lld\n", ansn.ss, ansn.ff);
    }
}