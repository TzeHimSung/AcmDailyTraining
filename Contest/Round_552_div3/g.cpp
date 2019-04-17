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

const int maxn = 1e7 + 10;
int n, vis[maxn], q[maxn];
ll ans = ll_inf, a, b;

int main()
{
    scanf("%d", &n);
    rep1(i, 1, n)
    {
        int x; scanf("%d", &x);
        if (vis[x])
        {
            if (ans > x)
            {
                ans = x;
                a = vis[x];
                b = i;
            }
        }
        else vis[x] = i;
    }
    rep1(i, 1, 1e7)
    {
        int len = 0;
        for (int j = i; j <= 1e7; j += i)
        {
            if (vis[j]) q[len++] = j;
        }
        if (len >= 2)
        {
            ll num1 = q[0], num2 = q[1], lcm = num1 * num2 / i;
            if (lcm < ans)
            {
                ans = lcm, a = vis[num1], b = vis[num2];
            }
        }
    }
    if (a > b) swap(a, b);
    printf("%lld %lld\n", a, b);
    return 0;
}