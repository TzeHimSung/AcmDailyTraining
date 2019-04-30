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

const int maxn = 55;
int a[maxn][maxn], n, solved = 0;
char s[maxn];

int check()
{
    rep1(i, 1, n)
    rep1(j, 1, n)
    if (!a[i][j]) return 0;
    return 1;
}

int putable(int x, int y)
{
    if (x == 1 || x == n || y == 1 || y == n) return 0;
    if (a[x - 1][y] || a[x + 1][y] || a[x][y - 1] || a[x][y + 1] || a[x][y]) return 0;
    return 1;
}

int main()
{
    scanf("%d", &n);
    rep1(i, 1, n)
    {
        scanf("%s", s + 1);
        rep1(j, 1, n)
        if (s[j] == '#') a[i][j] = 1; else a[i][j] = 0;
    }
    rep1(i, 2, n - 1)
    {
        rep1(j, 2, n - 1)
        if (putable(i, j))
        {
            a[i - 1][j] = a[i + 1][j] = a[i][j - 1] = a[i][j + 1] = a[i][j] = 1;
        }
    }
    if (check()) puts("YES");
    else puts("NO");
    return 0;
}