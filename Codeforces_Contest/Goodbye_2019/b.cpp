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

const int maxn = 2e5 + 10;
int t, n, a[maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        int p = -1, q = -1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (i == 1) continue;
            if (abs(a[i] - a[i - 1]) >= 2) p = i - 1, q = i;
        }
        if (p == -1) puts("NO");
        else printf("YES\n%d %d\n", p, q);
    }
    return 0;
}

