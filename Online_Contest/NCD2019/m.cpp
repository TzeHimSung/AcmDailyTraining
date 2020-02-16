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
        double b1, p1, b2, p2;
        scanf("%lf%lf%lf%lf", &b1, &p1, &b2, &p2);
        if (b1 * b2 == 0) {
            if (b1 == b2) puts("Lasy");
            else if (b1 == 0) puts("Congrats");
            else puts("HaHa");
            continue;
        }
        double tmp = p1 / p2 * (log(b1) / log(b2));
        if (tmp < 1) puts("Congrats");
        else if (tmp > 1) puts("HaHa");
        else puts("Lazy");
    }
    return 0;
}