#include <bits/stdc++.h>
using namespace std;
bitset<500> number[30];
char str[1001];
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; ++i) {
            scanf("%s", str);
            number[i] = bitset<500>(str);
        }
        int len = 1 << m;
        int ans = m + 1;
        for (int i = 1; i < len; ++i) {
            int t = i;
            int s = 0;
            bitset<500> now(0);
            for (int j = 0; j < m && t > 0; ++j) {
                if (t & 1) {
                    now = now | number[j];
                    s++;
                }
                t >>= 1;
            }
            if (now.count() == n) ans = min(ans, s);
        }
        if (ans == m + 1) printf("-1\n");
        else printf("%d\n", ans);
    }
}