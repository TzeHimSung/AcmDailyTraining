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

const int maxn = 5e5 + 10;
const int mod = 1e9 + 7;
ll ans = 0, a[maxn], comGcd = 0;
int n;

int main()
{
    scanf("%d", &n);
    rep1(i, 1, n)
    {
        scanf("%lld", &a[i]);
        comGcd = i == 1 ? a[i] : __gcd(comGcd, a[i]);
    }
    rep1(i, 1, n)
    {
        ll currGcd = a[i];
        rep1(j, i, n)
        {
            currGcd = __gcd(currGcd, a[j]);
            ans = (ans + currGcd) % mod;
            if (currGcd == comGcd)
            {
                ans = ((n - j) * comGcd + ans) % mod;
                break;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}