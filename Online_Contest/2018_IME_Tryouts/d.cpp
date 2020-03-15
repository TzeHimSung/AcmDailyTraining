#include <bits/stdc++.h>
using namespace std;
long long sum(long long x) {
    return x * (x + 1) / 2LL;
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long n;
        scanf("%lld", &n);
        long long l = -1, r = (long long)sqrt(4 * (n + 1)) + 1;
        while (l + 1 < r) {
            long long mid = l + r >> 1;
            if (sum(mid) <= n) l = mid;
            else r = mid;
        }
        printf("%lld\n", l);
    }
    return 0;
}