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

int t;
const int maxn = 1e4 + 10;
int n, a[maxn], k;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int cnt = 0;
        ll sum = 0;
        scanf("%d%d", &n, &k);
        rep1(i, 1, n)
        {
            scanf("%d", &a[i]);
            if (a[i] >= 0) sum += a[i]; else cnt++;
        }
        sot(a, n);
        if (k <= cnt)
        {
            rep1(i, 1, k) sum += -a[i];
            rep1(i, k + 1, cnt) sum += a[i];
        }
        else
        {
            rep1(i, 1, cnt) a[i] = -a[i], sum += a[i];
            sot(a, n);
            if ((k - cnt) & 1) sum -= a[1] * 2;
        }
        printf("%lld\n", sum);
    }
    return 0;
}