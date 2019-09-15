/* Contest shanghai_2019_online
 * Problem L
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

long long int f[11][1000001];

int calc(int n, int b) {
    int ret = 0;
    while (n) {
        ret += n % b;
        n /= b;
    }
    return ret;
}

int main(void) {
    int T;
    scanf("%d", &T);
    for (int i = 2; i <= 10; i++) {
        for (int j = 1; j <= 1000000; j++) {
            f[i][j] = f[i][j - 1] + calc(j, i);
        }
    }
    for (int i = 1; i <= T; i++) {
        int n, b;
        scanf("%d %d", &n, &b);
        printf("Case #%d: %lld\n", i, f[b][n]);
    }
    return 0;
}