/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 2020;
const ll mod = 1e9 + 7;
vector<ll>edge[maxn];
ll n, m, dp[maxn], cnt = 0, ans = 0;

ll dfs(ll cur) {
    if (dp[cur] != -1) return dp[cur];
    if (cur > m) {
        cnt++;
        dp[cur] = 1;
        return dp[cur];
    }
    ll sum = 0;
    for (auto x : edge[cur]) sum = ((dfs(x) % mod) + sum) % mod;
    dp[cur] = sum;
    return sum;
}

int main() {
    for (int i = 0; i < maxn; i++) dp[i] = -1;
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= m; i++) {
        ll x; scanf("%lld", &x);
        while (x--) {
            ll y; scanf("%lld", &y);
            edge[i].pb(y);
        }
        sort(edge[i].begin(), edge[i].end());
    }
    ll ans = dfs(1);
    printf("%lld %lld\n", ans, cnt);
    return 0;
}