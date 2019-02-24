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
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
ll n, k, sum = 0, a[maxn], ans[maxn];

int main()
{
    scanf("%lld%lld", &n, &k);
    rep1(i, 1, n)
    {
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    if (sum % k)
    {
        puts("No");
        return 0;
    }
    ll r = 0, tmp = 0, cnt1 = 0, cnt = sum / k;
    rep1(i, 1, n)
    {
        tmp += a[i];
        r++;
        if (tmp > cnt)
        {
            puts("No");
            return 0;
        }
        else if (tmp == cnt)
        {
            ans[++cnt1] = r;
            tmp = r = 0;
        }
    }
    puts("Yes");
    rep0(i, 1, k) printf("%lld ", ans[i]);
    printf("%lld\n", ans[k]);
    return 0;
}