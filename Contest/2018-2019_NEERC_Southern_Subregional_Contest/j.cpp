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

const int maxn = 3e4 + 10;
int t, n, m, k, dp[maxn], times[30];
char s[200010];

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        init(dp, 0);
        init(times, 0);
        ll ans = 0x3f3f3f3f3f3f3f3f;
        scanf("%d%d%d", &n, &m, &k);
        scanf("%s", s);
        int len = strlen(s);
        rep0(i, 0, len) times[s[i] - 'A' + 1]++;
        rep1(i, 1, 26)
        {
            for (int i = 1; i <= n; i++) dp[i] = 0; dp[0] = 1;
            rep1(j, 1, 26)
            {
                if (i == j) continue;
                for (int p = n; p >= times[j]; p--)
                    dp[p] |= dp[p - times[j]];
            }
            for (int j = min(n, times[i]); j >= 0; j--)
            {
                if (!dp[n - j]) continue;
                ans = min(ans, (ll)j * max((ll)0, (ll)times[i] - j - k + m + n));
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}