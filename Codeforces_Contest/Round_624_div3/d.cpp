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

int t, a, b, c;

int main() {
    scanf("%d", &t);
    while (t--) {
        int aa, bb, cc, ans = INT_MAX;
        scanf("%d%d%d", &a, &b, &c);
        for (int i = 1; i <= c; i++) {
            int curA = i, curB = 0, curC = 0;
            for (int j = 1; j * i <= 2 * b; j++) {
                curB = j * i;
                for (int k = 1; k * curB <= 2 * c; k++) {
                    curC = k * curB;
                    int tmp = abs(a - curA) + abs(b - curB) + abs(c - curC);
                    if (tmp < ans) {
                        ans = tmp;
                        aa = curA, bb = curB, cc = curC;
                    }
                }
            }
        }
        printf("%d\n%d %d %d\n", ans, aa, bb, cc);
    }
    return 0;
}