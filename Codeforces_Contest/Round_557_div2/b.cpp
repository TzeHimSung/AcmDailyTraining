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

const int maxn = 51;
int a[maxn][maxn], b[maxn][maxn], n, m;

int main()
{
    scanf("%d%d", &n, &m);
    rep1(i, 1, n) rep1(j, 1, m) scanf("%d", &a[i][j]);
    rep1(i, 1, n) rep1(j, 1, m)
    {
        scanf("%d", &b[i][j]);
        if (a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
    }
    int flag = 1;
    rep1(i, 1, n) rep1(j, 2, m)
    if (a[i][j] <= a[i][j - 1] || b[i][j] <= b[i][j - 1])
        flag = 0;
    rep1(j, 1, m) rep1(i, 2, n)
    if (a[i][j] <= a[i - 1][j] || b[i][j] <= b[i - 1][j])
        flag = 0;
    if (flag) puts("Possible"); else puts("Impossible");
    return 0;
}