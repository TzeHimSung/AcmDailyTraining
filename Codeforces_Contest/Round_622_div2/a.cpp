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
        int a, b, c, ans = 0, flag[10];
        memset(flag, 0, sizeof(flag));
        scanf("%d%d%d", &a, &b, &c);
        int tmp[3] = {a, b, c};
        sort(tmp, tmp + 3);
        a = tmp[2], b = tmp[1], c = tmp[0];
        while (1) {
            if (a >= 1 && !flag[1]) {
                a -= 1; flag[1] = 1; ans++; continue;
            }
            if (b >= 1 && !flag[2]) {
                b -= 1; flag[2] = 1; ans++; continue;
            }
            if (c >= 1 && !flag[3]) {
                c -= 1; flag[3] = 1; ans++; continue;
            }
            if (a >= 1 && b >= 1 && !flag[4]) {
                a -= 1, b -= 1; flag[4] = 1; ans++; continue;
            }
            if (a >= 1 && c >= 1 && !flag[5]) {
                a -= 1, c -= 1; flag[5] = 1; ans++; continue;
            }
            if (b >= 1 && c >= 1 && !flag[6]) {
                b -= 1, c -= 1; flag[6] = 1; ans++; continue;
            }
            if (a >= 1 && b >= 1 && c >= 1 && !flag[7]) {
                a -= 1, b -= 1, c -= 1; flag[7] = 1; ans++; continue;
            }
            break;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
7
1 2 1 3
0 0 0 0
9 1 7 4
2 2 3 5
2 3 2 5
3 2 2 5
4 4 4 7
 */