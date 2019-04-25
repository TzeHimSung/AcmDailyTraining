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

const int maxn = 1e3 + 10;
const int mod = 1e9 + 7;

int n, dp[maxn][maxn][2];

int main()
{
    scanf("%d", &n);
    rep1(i, 0, n)
    {
        dp[i][i + 1][0] = -int_inf;
        dp[n + 1][i][0] = -int_inf;
    }
    dp[n][n][0] = dp[n][n][1] = 0;
    for (int i = n; i >= 0; i--)
    {
        for (int j = i - (j == n); j >= 0; j--)
        {
            dp[i][j][0] = (dp[i][j + 1][1] + dp[i + 1][j][1]) % mod;
            dp[i][j][1] = (dp[i][j + 1][0] + dp[i + 1][j][1] + 1) % mod;
            dp[i][j][1] = (dp[i][j][0] + ((i + j) & 1)) % mod;
        }
    }
    printf("%d\n", dp[0][0][1]);
    return 0;
}