/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
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
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int n, a[maxn];
ll dp[maxn][2]; //0 is not reverse and 1 is reverse
string s[maxn][2];

int main()
{
    cin >> n;
    rep1(i, 1, n) cin >> a[i];
    //dp init
    rep1(i, 1, n)
    dp[i][0] = dp[i][1] = ll_inf;
    dp[1][0] = 0; dp[1][1] = a[1];
    rep1(i, 1, n)
    {
        cin >> s[i][0];
        s[i][1] = s[i][0];
        reverse(s[i][1].begin(), s[i][1].end());
    }
    int i;
    for (i = 2; i <= n; i++)
    {
        //if do not need to reverse
        if (s[i][0] >= s[i - 1][0])
            dp[i][0] = dp[i - 1][0];
        //if need to reverse
        if (s[i][1] >= s[i - 1][0])
            dp[i][1] = dp[i - 1][0] + a[i];
        //consider reverse i-1th string
        if (s[i][0] >= s[i - 1][1])
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        //consider reverse both string
        if (s[i][1] >= s[i - 1][1])
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + a[i]);
        //check go or not
        if (dp[i][0] == ll_inf && dp[i][1] == ll_inf)
            break;
    }
    if (i == n + 1)
        cout << min(dp[n][0], dp[n][1]) << endl;
    else
        cout << "-1" << endl;
    return 0;
}