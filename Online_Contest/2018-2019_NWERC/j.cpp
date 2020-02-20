#include <bits/stdc++.h>
using namespace std;
long long p[200001];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &p[i]);
    sort(p + 1, p + n + 1);
    p[0] = -1;
    if (p[n] == p[n - 1]) {
        printf("%lld\n", p[n] - p[n - 2]); return 0;
    }
    long long sum = p[n] - p[n - 1];
    long long Last = p[n - 1];
    long long maxT = __LONG_LONG_MAX__;
    long long T = 1;
    long long ans = 0;
    int tot = 0;
    for (int i = n - 1; i >= 1; --i) {
        ++tot;
        if (p[i] != p[i - 1]) {
            if (maxT >= Last - p[i]) {
                ans += T * (Last - p[i]);
                sum -= (T - 1) * (Last - p[i]);
                T = int(log2(tot)) + 1;
                if (T > 1) maxT = sum / (T - 1);
                else maxT = sum + 1;
                Last = p[i];
            } else break;
        }
    }
    if (T > 1) ans += T * maxT + sum % (T - 1);
    else ans += T * maxT;
    printf("%lld", ans);
    return 0;
}