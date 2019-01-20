/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
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
#define int int32_t
#define ll int64_t
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

const int mod = 1e9 + 7;
const int maxn = 2e5 + 10;
ll n, l, r, dp[maxn][3], f[3], ans = 0;

int main()
{
    cin >> n >> l >> r;
    f[0] = f[1] = f[2] = (r - l + 1) / 3;
    while ((r - l + 1) % 3)
    {
        f[l % 3]++;
        l++;
    }
    dp[1][0] = f[0], dp[1][1] = f[1], dp[1][2] = f[2];
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            dp[i][j] += (dp[i - 1][0] * f[j]) % mod;
            dp[i][j] %= mod;
            dp[i][(j + 1) % 3] += (dp[i - 1][1] * f[j]) % mod;
            dp[i][(j + 1) % 3] %= mod;
            dp[i][(j + 2) % 3] += (dp[i - 1][2] * f[j]) % mod;
            dp[i][(j + 2) % 3] %= mod;
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}