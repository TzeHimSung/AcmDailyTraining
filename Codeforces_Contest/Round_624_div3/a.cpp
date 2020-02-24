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
        int a, b, cnt = 0;
        scanf("%d%d", &a, &b);
        if (a == b) puts("0");
        else if (a < b) {
            if ((b - a) & 1) puts("1");
            else puts("2");
        } else {
            if ((b - a) & 1) puts("2");
            else puts("1");
        }
    }
    return 0;
}