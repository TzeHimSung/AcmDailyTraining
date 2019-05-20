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
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_int 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
ll n, dp[maxn], f[maxn];
int t;
char s[maxn];

int main()
{
    cin >> t;
    rep1(cnt, 1, t)
    {
        cin >> n ;
        scanf("%s", s + 1);
        cout << "Case " << cnt << ": ";
        rep1(i, 0, n) dp[i] = 0, f[i] = 0;
        ll ans = 0;
        rep1(i, 1, n)
        dp[i] = dp[i - 1] + (ll)(i + 1) * i / 2;
        rep1(i, 1, n)
        {
            f[i] = dp[n] - dp[n - i] - dp[i - 1];
            ans = (ans + f[i] * (int)s[i]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}