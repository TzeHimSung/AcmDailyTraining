/* basic header */
#include <stdio.h>

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int ans = 1, k = 2;
        while (k != 1) {
            if (k <= n) k <<= 1;
            else if (k <= (n << 1) && k > n) k = ((k - n) << 1) - 1;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}