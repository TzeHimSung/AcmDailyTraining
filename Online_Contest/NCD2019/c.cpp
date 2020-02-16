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

const int maxn = 1010, mod = 1e9 + 7;
int t, n, a[maxn], f[maxn], g[maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        int maxx = 0, num = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) {
            f[i] = 1, g[i] = 1;
            for (int j = 1; j < i; j++)
                if (a[j] < a[i]) {
                    if (f[i] < f[j] + 1) f[i] = f[j] + 1, g[i] = g[j];
                    else if (f[i] == f[j] + 1) g[i] = (g[i] + g[j]) % mod;
                }
        }
        for (int i = 1; i <= n; i++)
            if (maxx < f[i]) maxx = f[i], num = g[i];
            else if (maxx == f[i]) num = (num + g[i]) % mod;
        printf("%d %d\n", maxx, num);
    }
    return 0;
}