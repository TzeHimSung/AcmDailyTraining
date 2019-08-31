/* Contest yinchuan_2019_online
 * Problem D
 * Team: Make One For Us
 */
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("Case #%d: %.6f %.6f\n", i, n == 1 ? 1 : 1.0 / 2, m == 1 ? 1 : ((double) (m - 1) / 2 + 1) / m);
    }
    return 0;
}