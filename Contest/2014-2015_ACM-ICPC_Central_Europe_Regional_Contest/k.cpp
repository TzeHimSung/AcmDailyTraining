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

struct Item
{
    int c, v;
    bool operator<(const Item &rhs) const
    {
        return v < rhs.v;
    }
};
const int maxn = 150000 + 10;
Item item[maxn];
int n, k, dp[maxn][11];
//dp[i][j]: max benefit
//first dir: from Ith to Nth items
//second dir: remain J times to use magic
//dp[1][k] should be answer

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        rep1(i, 1, n) scanf("%d%d", &item[i].v, &item[i].c);
        sot(item, n);
        //init
        rep1(i, 0, k) dp[n + 1][i] = 0;
        for (int i = n; i >= 1; i--)
            for (int j = 0; j <= k; j++)
            {
                if (!j) //border
                    dp[i][j] = max(dp[i + 1][j], item[i].v - item[i].c);
                else //compare two situations: use or not use magic
                    dp[i][j] = max(dp[i + 1][j], min(item[i].v - item[i].c, dp[i + 1][j - 1] - item[i].c)); //fuck
            }
        printf("%d\n", dp[1][k]);
    }
    return 0;
}