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

const int maxn = 2e5 + 10;
int t;
ll a[maxn];

int main()
{
    scanf("%d", &t);
    for (int cnt = 1; cnt <= t; cnt++)
    {
        a[0] = 0;
        if (cnt != 1) puts("");
        ll n; scanf("%lld", &n);
        for (int i = 2; i <= n; i++)
        {
            ll x; scanf("%lld", &x);
            a[i] = a[i - 1] + x;
        }
        ll ans = 0, k = 0, l = 0, r = n + 1;
        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
            {
                l++; ans += k;
            }
            else
            {
                r--; k += a[r] - a[l]; ans += k;
            }
            if (i != 1) printf(" ");
            printf("%lld", ans);
        }
    }
    return 0;
}