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

const int maxn = 2e3 + 10;
const int maxm = 2e5 + 10;
int n, m, k, a[maxm], off[maxn], dp[maxn], s[maxn];

int calc(int num)
{
    // if (num > k) return 0;
    // ll ret = 1e17;
    // rep1(i, 1, k)
    // {
    //     if (!off[i]) continue;
    //     ret = min(ret, calc(num - i) + s[num] - s[num - i + off[i]]);
    // }
    // ret = min(ret, s[num]);
    // return dp[num] = ret;
    if (num > k) return 0;
    int &ans = dp[num]; //
    if (~ans) return ans;
    ans = int_inf;
    ans = min(ans, calc(num + 1) + a[num]);
    rep1(i, 1, k)
    {
        int x = i, y = off[i];
        if (!y) continue;
        if (num + x <= k + 1)
            ans = min(ans, calc(num + x) + s[num + x - 1] - s[num + y - 1]);
    }
    return ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    rep1(i, 1, n) scanf("%d", &a[i]);
    sot(a, n);
    rep1(i, 1, k)
    {
        dp[i] = -1;
        s[i] = s[i - 1] + a[i];
    }
    rep1(i, 1, m)
    {
        int num, y; scanf("%d%d", &num, &y);
        if (num > k) continue;
        off[num] = max(off[num], y);
    }
    printf("%d\n", calc(1));
    return 0;
}