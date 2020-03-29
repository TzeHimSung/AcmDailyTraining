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

const int MAXN = 2e5 + 10;
int n, ans1 = 0, ans2 = 0, maxn = 0, a[MAXN], b[MAXN], f1[MAXN], f2[MAXN], f3[MAXN];

int main() {
    for (int i = 0; i < MAXN; i++) f1[i] = f2[i] = f3[i] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i], &b[i]);
        f1[a[i]]++, f2[b[i]]++, f3[a[i]]++, f3[b[i]]--;
        maxn = max(maxn, b[i]);
    }
    for (int i = 1; i <= maxn; i++) f1[i] += f1[i - 1], f2[i] += f2[i - 1];
    for (int i = 1; i <= n; i++) ans1 = max(ans1, f1[b[i] - 1] - f2[a[i]]);
    for (int i = 1; i <= maxn; i++) {
        f3[i] += f3[i - 1];
        ans2 = max(ans2, f3[i]);
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}