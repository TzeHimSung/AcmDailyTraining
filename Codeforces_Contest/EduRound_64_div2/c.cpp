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
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curPos<<1
#define rson (curPos<<1)+1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
int n, z, a[maxn];

int main()
{
    scanf("%d%d", &n, &z);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int l = 0, r = n / 2 + 1;
    while (r - l > 1)
    {
        int mid = l + r >> 1, sign = 1;
        for (int i = 0; i < mid; i++)
            sign &= (a[n - mid + i] - a[i] >= z);
        if (sign) l = mid; else r = mid;
    }
    printf("%d\n", l);
    return 0;
}
