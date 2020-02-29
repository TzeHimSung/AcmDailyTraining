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

const int maxn = 1010;
int p, mi[maxn], ans[maxn], tmp[maxn];

void mul(int a[maxn], int b[maxn]) {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 1; i <= 500; i++)
        for (int j = 1; j <= 500; j++)
            tmp[i + j - 1] += a[i] * b[j];
    for (int i = 1; i <= 500; i++) {
        tmp[i + 1] += tmp[i] / 10;
        tmp[i] %= 10;
    }
    memcpy(a, tmp, sizeof(tmp));
}

void qp() {
    ans[1] = 1, mi[1] = 2;
    while (p) {
        if (p & 1) mul(ans, mi);
        p >>= 1;
        mul(mi, mi);
    }
    ans[1]--;
}

int main() {
    scanf("%d", &p);
    printf("%d\n", (int)(log10(2)*p + 1));
    qp();
    for (int i = 500; i >= 1; i--) {
        if (i != 500 && i % 50 == 0) printf("\n%d", ans[i]);
        else printf("%d", ans[i]);
    }
    return 0;
}