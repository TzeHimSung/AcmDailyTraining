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

int n, k, maxx = 0;
map<int, int>cnt;

int main() {
    cnt.clear();
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k + 1; i++) {
        printf("?");
        for (int j = 1; j <= k + 1; j++) {
            if (i == j) continue;
            printf(" %d", j);
        }
        puts("");
        fflush(stdout);
        int pos, val;
        scanf("%d%d", &pos, &val);
        cnt[val]++; maxx = max(maxx, val);
    }
    printf("! %d\n", cnt[maxx]);
    fflush(stdout);
    return 0;
}
