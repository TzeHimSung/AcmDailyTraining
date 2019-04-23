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

const int maxn = 3e5 + 10;
int n, m;
ll s, currX, lastX, currP, ansPos = 0, gcd;

int main()
{
    scanf("%d%d", &n, &m);
    rep1(i, 1, n)
    {
        scanf("%lld", &currX);
        if (i == 1) s = currX;
        else if (i == 2) gcd = currX - lastX;
        else gcd = __gcd(gcd, currX - lastX);
        lastX = currX;
    }
    rep1(i, 1, m)
    {
        scanf("%lld", &currP);
        if (!(gcd % currP)) ansPos = i;
    }
    if (!ansPos) puts("NO");
    else printf("YES\n%lld %lld\n", s, ansPos);
    return 0;
}