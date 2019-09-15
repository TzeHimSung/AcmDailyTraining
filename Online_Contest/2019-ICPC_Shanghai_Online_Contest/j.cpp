/* Contest shanghai_2019_online
 * Problem J
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

const long long int p = 1e9 + 7;
long long int f[2][150002];

int main(void) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        vector <int> arr(n + 1);
        long long int sum = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        sort(arr.begin(), arr.end());
        memset(f, 0, sizeof(f));
        long long int ans = 0;
        int cur = 0;
        f[!cur][0] = 1;
        for (int i = n; i >= 1; i--) {
            for (int x = 0; x <= 150000; x++) {
                f[cur][x] = f[!cur][x];
                if (x >= arr[i]) {
                    (f[cur][x] += f[!cur][x - arr[i]]) %= p;
                }
                int s_pi = x + arr[i];
                int s_rem = sum - s_pi;
                if (s_pi >= s_rem && s_rem >= x) {
                    (ans += f[!cur][x]) %= p;
                }
            }
            cur = !cur;
        }
        printf("%lld\n", ans % p);
    }
    return 0;
}