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
        int base = 0;
        vector<int>v;
        for (int i = 1; i < n; i++) {
            if (a[i] == -1 && a[i + 1] != -1) v.pb(a[i + 1]);
            else if (a[i] != -1 && a[i + 1] == -1) v.pb(a[i]);
            else if (a[i] != -1 && a[i + 1] != -1) base = max(base, abs(a[i] - a[i + 1]));
        }
        if (v.empty()) {
            puts("0 0");
            continue;
        }
        sort(v.begin(), v.end());
        int k = (v.back() + *v.begin()) / 2;
        printf("%d %d\n", max({v.back() - k, k - v[0], base}), k);
    }
    return 0;
}

