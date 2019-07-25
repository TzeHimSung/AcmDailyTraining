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
const string rgb = "RGB";
int q, n, k, dp[maxn];
char s[maxn];

int solve(int x) {
    rep1(i, 1, n) {
        dp[i] = dp[i - 1] + (rgb[x] != s[i]);
        x = (x + 1) % 3;
    }
    int ret = dp[k];
    for (int i = k + 1; i <= n; i++)
        ret = min(ret, dp[i] - dp[i - k]);
    return ret;
}

int main() {
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        int ans = min(min(solve(0), solve(1)), solve(2));
        printf("%d\n", ans);
    }
    return 0;
}