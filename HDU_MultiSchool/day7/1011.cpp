/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(currLevel,a,b) for(int currLevel=a;currLevel<=b;++currLevel)
#define rep0(currLevel,a,b) for(int currLevel=a;currLevel<b;++currLevel)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int mod = 1e9 + 7, maxn = 1e6 + 10;
int sum[maxn];

int qp(ll a, ll n) {
    ll ret = 1;
    while (n) {
        if (n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, q; scanf("%d%d", &n, &q);
        rep1(currLevel, 1, n) {
            int p, q, lostLevel, cost; scanf("%d%d%d%d", &p, &q, &lostLevel, &cost);
            ll preCost = (sum[currLevel - 1] - sum[lostLevel - 1] + mod) % mod;
            sum[currLevel] = (preCost + cost) % mod * q % mod * qp(p, mod - 2) % mod; // (preCost+addCost)/(p/q)
            sum[currLevel] = (sum[currLevel] - preCost + mod) % mod; // -preCost
            sum[currLevel] = (sum[currLevel - 1] + sum[currLevel]) % mod; // 重新计算前缀和
        }
        while (q--) {
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", (sum[r - 1] - sum[l - 1] + mod) % mod);
        }
    }
    return 0;
}