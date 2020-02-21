#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

struct node {
    int t1, t2, e1, e2;
} q[510];
ll dp[510][510], tmp[510][510];
int main() {
    int n, s1, s2;
    scanf("%d%d%d", &n, &s1, &s2);
    for (int i = 1; i <= n; i++)
        scanf("%d%d%d%d", &q[i].e1, &q[i].t1, &q[i].e2, &q[i].t2);
    sort(q + 1, q + 1 + n, [](node a, node b) {
        return a.e1 < b.e1;
    });
    for (int i = 0; i <= s1; i++)
        for (int j = 0; j <= s2; j++)
            dp[i][j] = 1e18;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s1; j++)
            for (int k = 0; k <= s2; k++)
                tmp[j][k] = dp[j][k];

        for (int j = s1; j >= 0; j--)
            for (int k = s2; k >= 0; k--)
                if (dp[j][k] != 1e18) {
                    if (j < s1) {
                        int minj = j + q[i].e1, mink = k;
                        if (minj > s1) {
                            mink = min(s2, minj - s1 + k);
                            minj = s1;
                        }
                        tmp[minj][mink] = min(tmp[minj][mink], dp[j][k] + q[i].t1);
                    }
                    int mink = min(s2, k + q[i].e2);
                    tmp[j][mink] = min(tmp[j][mink], dp[j][k] + q[i].t2);
                }

        for (int j = 0; j <= s1; j++)
            for (int k = 0; k <= s2; k++)
                dp[j][k] = tmp[j][k];
    }
    if (dp[s1][s2] == 1e18 || dp[s1][s2] == 0)
        dp[s1][s2] = -1;
    printf("%lld\n", dp[s1][s2]);
}