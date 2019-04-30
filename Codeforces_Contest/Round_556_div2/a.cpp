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

const int maxn = 1e2 + 10;
int n, m, r, minn = 2000, maxx = 0;

int main()
{
    scanf("%d%d%d", &n, &m, &r);
    rep1(i, 1, n)
    {
        int x; scanf("%d", &x); minn = min(minn, x);
    }
    rep1(i, 1, m)
    {
        int x; scanf("%d", &x); maxx = max(maxx, x);
    }
    if (maxx > minn) printf("%d\n", maxx * (r / minn) + r % minn);
    else printf("%d\n", r);
    return 0;
}