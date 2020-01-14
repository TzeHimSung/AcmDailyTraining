#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second

const int N = 1e6 + 10;
vector<ll> dp[N];
vector<int> a[N];
int main() {
    int n, h; scanf("%d%d", &n, &h);
    for (int i = 1; i <= n; i++) {
        a[i].resize(h + 1);
        dp[i].resize(h + 1);
        for (int j = 1; j <= h; j++)
            scanf("%d", &a[i][j]);
        dp[i][1] = a[i][1];
    }

    a[0].resize(h + 1); a[n + 1].resize(h + 1);
    dp[0].resize(h + 1); dp[n + 1].resize(h + 1);
    for (int i = 1; i <= h; i++)a[0][i] = a[n + 1][i] = dp[0][i] = dp[n + 1][i] = 0;
    for (int j = 2; j <= h; j++) {
        for (int i = 1; i <= n; i++) {
            dp[i][j] = a[i][j] + max(max(dp[i - 1][j - 1], dp[i + 1][j - 1]), dp[i][j - 1]);
        }
    }
    ll maxx = 0;
    for (int i = 1; i <= n; i++)maxx = max(maxx, dp[i][h]);
    printf("%lld\n", maxx);
}