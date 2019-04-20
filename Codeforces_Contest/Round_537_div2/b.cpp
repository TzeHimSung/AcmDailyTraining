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
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_int 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int n, k, m, a[maxn];
ll f[maxn];
double ans = 0;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    scanf("%d%d%d", &n, &k, &m);
    rep1(i, 1, n)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + 1 + n, cmp);
    f[0] = 0;
    rep1(i, 1, n) f[i] = f[i - 1] + a[i];
    rep1(i, max(1, n - m), n)
    {
        //del is the number of deleted element, curr means the number of the operation
        int del = n - i, curr = min((ll)k * i, (ll)m - del);
        ans = max(ans, (double)(f[i] + curr) / (double)i);
    }
    printf("%.16f\n", ans);
    return 0;
}