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

const int maxn = 1e6 + 10;
int n, a[maxn], pos[maxn], d[maxn], preSum[maxn], maxx;

int solve(int x) {
    if (x < maxx) return -int_inf;
    if (d[x]) return d[x];
    int res = 0, i = 0;
    while (i < n) {
        res += x;
        res = min(res, 1000000);
        i = pos[res];
        res = preSum[i];
        d[x]++;
    }
    return d[x];
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        maxx = max(maxx, a[i]);
        preSum[i] = preSum[i - 1] + a[i];
        for (int j = preSum[i - 1]; j < preSum[i]; j++) pos[j] = i - 1;
    }
    for (int i = preSum[n]; i <= 1000000; i++) pos[i] = n;
    int q; scanf("%d", &q);
    while (q--) {
        int x; scanf("%d", &x);
        int ret = solve(x);
        if (ret != -int_inf) printf("%d\n", solve(x));
        else puts("Impossible");
    }
    return 0;
}