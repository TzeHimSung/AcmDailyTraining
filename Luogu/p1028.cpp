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

int n, dp[1100];

ll solve(int x) {
    if (dp[x]) return dp[x];
    if (!x || x == 1) return 0;
    ll ret = x / 2;
    for (int i = 1; i <= x / 2; i++) ret += solve(i);
    dp[x] = ret;
    return ret;
}

int main() {
    for (int i = 0; i < 1100; i++) dp[i] = 0;
    scanf("%d", &n);
    printf("%lld\n", solve(n) + 1);
    return 0;
}