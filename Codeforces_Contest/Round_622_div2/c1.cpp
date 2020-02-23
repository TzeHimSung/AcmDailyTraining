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

const int maxn = 1010;
int n, a[maxn], m[maxn], ansList[maxn];
ll ans = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &m[i]);
    for (int i = 1; i <= n; i++) {
        ll total = 0;
        for (int j = 1; j < i; j++) a[j] = 0;
        for (int j = i + 1; j <= n; j++) a[j] = 0;
        a[i] = m[i]; total += a[i];
        for (int j = i - 1; j >= 1; j--) {
            a[j] = min(m[j], a[j + 1]);
            total += a[j];
        }
        for (int j = i + 1; j <= n; j++) {
            a[j] = min(m[j], a[j - 1]);
            total += a[j];
        }
        if (total > ans) {
            ans = total;
            for (int i = 1; i <= n; i++) ansList[i] = a[i];
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", ansList[i]);
    return 0;
}