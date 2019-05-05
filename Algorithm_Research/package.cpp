// // 01 package
//
// /* basic header */
// #include <iostream>
// #include <cstdio>
// #include <cstdlib>
// #include <string>
// #include <cstring>
// #include <cmath>
// #include <cstdint>
// #include <climits>
// #include <float.h>
// /* STL */
// #include <vector>
// #include <set>
// #include <map>
// #include <queue>
// #include <stack>
// #include <algorithm>
// #include <array>
// #include <iterator>
// /* define */
// #define ll long long
// #define dou double
// #define pb emplace_back
// #define mp make_pair
// #define fir first
// #define sec second
// #define sot(a,b) sort(a+1,a+1+b)
// #define rep1(i,a,b) for(int i=a;i<=b;++i)
// #define rep0(i,a,b) for(int i=a;i<b;++i)
// #define repa(i,a) for(auto &i:a)
// #define eps 1e-8
// #define int_inf 0x3f3f3f3f
// #define ll_inf 0x7f7f7f7f7f7f7f7f
// #define lson curPos<<1
// #define rson curPos<<1|1
// /* namespace */
// using namespace std;
// /* header end */

// const int maxn = 1e3 + 10;
// struct Item
// {
//     int val, cost;
// };
// int dp[maxn][maxn];
// // int dp[maxn];
// Item item[maxn];

// int main()
// {
//     int n, cap; scanf("%d%d", &n, &cap);
//     rep1(i, 1, n) scanf("%d%d", &item[i].cost, &item[i].val);
//     rep1(i, 1, n)
//     {
//         rep1(j, item[i].cost, cap)
//         if (j < item[i].cost) dp[i][j] = dp[i - 1][j];
//         else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - item[i].cost] + item[i].val);
//     }
//     printf("%d\n", dp[n][cap]);
//     // int n, m; scanf("%d%d", &n, &m);
//     // rep1(i, 1, n) scanf("%d%d", &item[i].cost, &item[i].val);
//     // rep1(i, 1, n)
//     // {
//     //     for (int j = m; j >= item[i].cost; j--)
//     //         dp[j] = max(dp[j], dp[j - item[i].cost] + item[i].val);
//     // }
//     // printf("%d\n", dp[m]);
//     return 0;
// }

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

/* value and function */

int main()
{
    /* main body */
    return 0;
}