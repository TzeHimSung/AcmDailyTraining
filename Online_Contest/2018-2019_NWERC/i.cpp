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
int n, a[maxn];
double ans = INT_MAX;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
        if (a[i] > i) return puts("-1"), 0;
        ans = min(ans, double(a[i]) / (i));
    }
    printf("%.10f\n", ans);
    return 0;
}