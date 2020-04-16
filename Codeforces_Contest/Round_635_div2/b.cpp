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

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int x, n, m;
        scanf("%d%d%d", &x, &n, &m);
        while (n > 0 && x > 20) {
            x = (x / 2) + 10;
            n--;
        }
        while (m > 0) {
            x -= 10;
            m--;
        }
        if (x > 0) printf("NO\n");
        else printf("YES\n");
    }
}