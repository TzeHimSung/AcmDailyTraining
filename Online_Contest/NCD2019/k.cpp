#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

ll a[100010];
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, x;
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), a[i] += a[i - 1];
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int r = upper_bound(a + 1, a + 1 + n, a[i - 1] + x - 1) - a - 1;
            ans += r - i + 1;
        }
        printf("%lld\n", ans);
    }
}