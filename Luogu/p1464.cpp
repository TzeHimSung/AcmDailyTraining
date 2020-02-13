/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(x,y) sort(x+1,x+1+y)
#define rep1(i,x,y) for(int i=x;i<=y;++i)
#define rep0(i,x,y) for(int i=x;i<y;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

ll dp[22][22][22], a, b, c;

ll solve(ll x, ll y, ll z) {
    if (x <= 0 || y <= 0 || z <= 0) return 1;
    else if (dp[x][y][z]) return dp[x][y][z];
    else if (x > 20 || y > 20 || z > 20) dp[x][y][z] = solve(20, 20, 20);
    else if (x < y && y < z) dp[x][y][z] = solve(x, y, z - 1) + solve(x, y - 1, z - 1) - solve(x, y - 1, z);
    else dp[x][y][z] = solve(x - 1, y, z) + solve(x - 1, y - 1, z) + solve(x - 1, y, z - 1) - solve(x - 1, y - 1, z - 1);
    return dp[x][y][z];
}

int main() {
    memset(dp, 0, sizeof(dp));
    while (~scanf("%lld%lld%lld", &a, &b, &c)) {
        if (a == -1 && b == -1 && c == -1) break;
        printf("w(%lld, %lld, %lld) = ", a, b, c);
        if (a > 20) a = 21;
        if (b > 20) b = 21;
        if (c > 20) c = 21;
        printf("%lld\n", solve(a, b, c));
    }
    return 0;
}