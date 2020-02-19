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

int a[4], k;

int main() {
    for (int i = 0; i < 4; i++) {
        int x, y; scanf("%d.%d", &x, &y);
        a[i] = x * 100 + y;
    }
    int x, y; scanf("%d.%d", &x, &y); k = x * 100 + y;
    sort(a, a + 4);
    int sum = a[1] + a[2] + a[3];
    if (k * 3 >= sum) return puts("infinite"), 0;
    if (k * 3 - a[1] - a[2] < a[0]) return puts("impossible"), 0;
    printf("%d.", (k * 3 - a[1] - a[2]) / 100);
    int tmp = (k * 3 - a[1] - a[2]) % 100;
    if (tmp < 10) printf("0%d\n", tmp); else printf("%d\n", tmp);
    return 0;
}