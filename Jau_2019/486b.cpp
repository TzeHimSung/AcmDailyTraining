/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdint>
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
#define int int32_t
#define ll int64_t
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
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e2 + 10;
int n, m, a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];

bool judge()
{
    rep1(i, 1, n)
    rep1(j, 1, m)
    if (!b[i][j])
    {
        rep1(k, 1, n) a[k][j] = 0;
        rep1(k, 1, m) a[i][k] = 0;
    }
    rep1(i, 1, n)
    rep1(j, 1, m)
    if (a[i][j] == 1)
    {
        rep1(k, 1, n) c[k][j] = 1;
        rep1(k, 1, m) c[i][k] = 1;
    }
    rep1(i, 1, n)
    rep1(j, 1, m)
    if (b[i][j] != c[i][j])
        return true;
    puts("YES");
    rep1(i, 1, n)
    {
        printf("%d", a[i][1]);
        rep1(j, 2, m)
        printf(" %d", a[i][j]);
        puts("");
    }
    return false;
}

int main()
{
    cin >> n >> m;
    rep1(i, 1, n)
    rep1(j, 1, m)
    {
        a[i][j] = 1;
        scanf("%d", &b[i][j]);
    }
    if (judge())
        puts("NO");
    return 0;
}