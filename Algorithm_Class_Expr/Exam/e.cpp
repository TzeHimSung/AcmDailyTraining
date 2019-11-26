#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3 + 10;
pair<int, int>a[maxn];
int n, dp[maxn], ans = 0;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) dp[i] = 1;
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j].first < a[i].first && a[j].second < a[i].second)
                dp[i] = max(dp[i], dp[j] + 1);
            ans = max(ans, dp[i]);
        }
    }
    printf("%d\n", ans);
    return 0;
}