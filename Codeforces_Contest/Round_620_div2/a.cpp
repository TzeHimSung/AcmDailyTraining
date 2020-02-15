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
        ll x, y, a, b; scanf("%lld%lld%lld%lld", &x, &y, &a, &b);
        if ((y - x) % (a + b) == 0) printf("%lld\n", (y - x) / (a + b));
        else puts("-1");
    }
    return 0;
}