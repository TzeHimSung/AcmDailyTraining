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

const int maxn = 1e6 + 10;
int n, p;
double a[maxn], len[maxn], ans[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf", &a[i]);
    for (int i = 1; i <= n; i++) {
        ans[++p] = a[i];
        len[p] = 1;
        while (p > 1 && ans[p - 1] > ans[p]) {
            ans[p - 1] = (ans[p] * len[p] + ans[p - 1] * len[p - 1]) / (len[p] + len[p - 1]);
            len[p - 1] += len[p];
            p--;
        }
    }
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= len[i]; j++) {
            printf("%.12f ", ans[i]);
        }
    }
    return 0;
}