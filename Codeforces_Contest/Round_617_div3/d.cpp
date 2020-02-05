/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
int n, a, b, k, ans, h[maxn];

int main() {
    scanf("%d%d%d%d", &n, &a, &b, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        h[i] %= a + b;
        if (!h[i]) h[i] = a + b;
        h[i] = (h[i] - 1) / a;
    }
    sort(h, h + n);
    for (int i = 0; i < n && k >= h[i]; i++) {
        k -= h[i]; ans++;
    }
    printf("%d\n", ans);
    return 0;
}