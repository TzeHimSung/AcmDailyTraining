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

const int maxn = 1e7 + 1;
int dp[maxn];

int main() {
    int n; scanf("%d", &n);
    dp[n] = 0;
    int i = n;
    for (; i > 0;) {
        if (i >= 100) {
            dp[i % 100] = dp[i % 100] + dp[i] + i / 100;
            i %= 100;
        } else if (i >= 20) {
            dp[i % 20] = dp[i % 20] + dp[i] + i / 20;
            i %= 20;
        } else if (i >= 10) {
            dp[i % 10] = dp[i % 10] + dp[i] + i / 10;
            i %= 10;
        } else if (i >= 5) {
            dp[i % 5] = dp[i % 5] + dp[i] + i / 5;
            i %= 5;
        } else {
            dp[0] = dp[i] + i;
            i = 0;
        }
    }
    printf("%d\n", dp[0]);
    return 0;
}