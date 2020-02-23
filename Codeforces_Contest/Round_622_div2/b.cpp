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
        printf("%d %d\n", max(1, min(n, x + y + 1 - n)), min(x + y - 1, n));
    }
    return 0;
}