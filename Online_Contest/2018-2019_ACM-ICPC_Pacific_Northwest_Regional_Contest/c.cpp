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
const ll mod = 998244353;
map<ll, ll>cnt;
vector<ll>v;
ll a[maxn], dp[maxn][maxn], ans[maxn][maxn];

int main()
{
    int n, k;
    ll x;
    scanf("%d%d", &n, &k);
    rep1(i, 1, n)
    {
        scanf("%lld", &x);
        if (!cnt[x]) v.push_back(x);
        cnt[x]++;
    }
    n = v.size();
    rep1(i, 1, n) a[i] = cnt[v[i - 1]];
    rep1(i, 1, n)
    {
        dp[1][i] = a[i] % mod;
        ans[1][i] = (dp[1][i] + ans[1][i - 1]) % mod;
    }
    rep1(i, 2, k)
    {
        rep1(j, 1, n)
        {
            dp[i][j] = a[j] * ans[i - 1][j - 1] % mod;
            ans[i][j] = (dp[i][j] + ans[i][j - 1]) % mod;
        }
    }
    printf("%lld\n", ans[k][n]);
    return 0;
}