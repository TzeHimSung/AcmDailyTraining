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
int t, n, a[maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        a[0] = a[n + 1] = -1;
        int maxx = -1, minn = 1e9;
        for (int i = 1; i <= n; i++) {
            if (a[i] == -1) {
                if (a[i - 1] != -1) minn = min(minn, a[i - 1]), maxx = max(maxx, a[i - 1]);
                if (a[i + 1] != -1) minn = min(minn, a[i + 1]), maxx = max(maxx, a[i + 1]);
            }
        }
        int k = maxx + minn >> 1, ans = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == -1) a[i] = k;
            if (i != 1) ans = max(ans, abs(a[i] - a[i - 1]));
        }
        printf("%d %d\n", ans, k);
    }
    return 0;
}