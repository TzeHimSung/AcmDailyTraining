/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        int o1min = x == 1 ? 2 : 1, o2max = y == n ? n - 1 : n;
        printf("%d %d\n", min(x, x + y + 1 - n), min(x + y - 1, n));
    }
    return 0;
}