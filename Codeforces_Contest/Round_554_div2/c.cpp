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

ll a, b, minLcm = 0, ans = 0, delta;

ll lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

int main()
{
    scanf("%lld%lld", &a, &b); delta = abs(b - a);
    minLcm = lcm(a, b);
    for (ll i = 1; i * i <= delta; i++)
    {
        if (!(delta % i))
        {
            ll tmp = i - (a % i);
            if (lcm(a + tmp, b + tmp) < minLcm)
            {
                minLcm = lcm(a + tmp, b + tmp);
                ans = tmp;
            }
            tmp = (delta / i) - (a % (delta / i));
            if (lcm(a + tmp, b + tmp) < minLcm)
            {
                minLcm = lcm(a + tmp, b + tmp);
                ans = tmp;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}