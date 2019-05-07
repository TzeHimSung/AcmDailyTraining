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

const int maxn = 2e3 + 10;
ll n, a[2][maxn], len[2], ans;

int main()
{
    scanf("%lld", &n);
    while (n--)
    {
        int x; scanf("%d", &x);
        a[x % 2][len[x % 2]++] = x;
    }
    sort(a[0], a[0] + len[0]);
    sort(a[1], a[1] + len[1]);
    for (int i = len[0] > len[1] ? 0 : 1; len[i] >= 0; i = (i + 1) % 2) len[i]--;
    for (int i = len[0] > len[1] ? 0 : 1; len[i] >= 0; len[i]--) ans += a[i][len[i]];
    printf("%lld\n", ans);
}