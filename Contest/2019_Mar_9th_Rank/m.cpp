/*

补题 dp

*/

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

const int maxn = 3e3 + 10;
struct Node
{
    int pos, cost;

    bool operator<(const Node &rhs)const
    {
        return pos < rhs.pos;
    }
};
Node room[maxn];
int n;
ll dp[2][maxn], minn[maxn];

int main()
{
    while (cin >> n)
    {
        rep1(i, 1, n) minn[i] = dp[1][i] = ll_inf, dp[0][i] = 0;
        rep1(i, 1, n) cin >> room[i].pos >> room[i].cost;
        sot(room, n);
        minn[1] = dp[1][1] = room[1].cost;
        rep1(i, 2, n)
        {
            rep1(j, 1, i)
            {
                if (i == j) dp[i & 1][j] = minn[i - 1] + room[i].cost;
                else dp[i & 1][j] = dp[(i - 1) & 1][j] + room[i].pos - room[j].pos;
                minn[i] = min(minn[i], dp[i & 1][j]);
            }
        }
        cout << minn[n] << endl;
    }
    return 0;
}