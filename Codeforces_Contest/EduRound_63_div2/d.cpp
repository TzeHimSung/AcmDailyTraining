/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <climits>
#include <float.h>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 3e5 + 10;
ll a[maxn], f[maxn], dp[2][maxn], x, ans = 0;
int n;

int main()
{
    scanf("%d%lld", &n, &x);
    rep1(i, 1, n) scanf("%lld", &a[i]);
    f[n + 1] = 0;
    for (int i = n; i >= 1; i--)
        f[i] = max(a[i], f[i + 1] + a[i]);
    rep1(i, 1, n)
    {
        dp[0][i] = max(a[i], dp[0][i - 1] + a[i]);
        dp[1][i] = a[i] * x;
        if (max(dp[0][i - 1], dp[1][i - 1]) > 0)
            dp[1][i] += max(dp[0][i - 1], dp[1][i - 1]);
        ans = max(ans, max(dp[0][i], dp[1][i] + f[i + 1]));
        ans = max(ans, dp[1][i]);
    }
    printf("%lld\n", ans);
    return 0;
}