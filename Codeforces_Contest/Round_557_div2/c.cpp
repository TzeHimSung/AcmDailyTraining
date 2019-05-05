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

const int maxn = 1e5 + 10;
int n, k, a[maxn], l[maxn], r[maxn];

int main()
{
    scanf("%d%d", &n, &k);
    int ans = (n - 2) * 3 + 4;
    rep1(i, 1, k)
    {
        scanf("%d", &a[i]);
        r[a[i]] = i;
        if (!l[a[i]]) l[a[i]] = i;
    }
    rep1(i, 1, n)
    {
        if (!l[i]) continue;
        if (i == 1)
        {
            if (r[2] && l[1] < r[2]) ans--;
        }
        else if (i == n)
        {
            if (r[n - 1] && l[n] < r[n - 1]) ans--;
        }
        else
        {
            if (l[i] < r[i + 1]) ans--;
            if (l[i] < r[i - 1]) ans--;
        }
        if (l[i]) ans--;
    }
    printf("%d\n", ans);
    return 0;
}