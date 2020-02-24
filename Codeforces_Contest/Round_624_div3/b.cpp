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
const int maxn = 110;
int n, m, a[maxn], p[maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
        for (int cnt = 1; cnt <= n; cnt++) {
            for (int i = 1; i <= m; i++) {
                if (a[p[i]] > a[p[i] + 1]) swap(a[p[i]], a[p[i] + 1]);
            }
        }
        int flag = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i + 1]) {
                flag = 0;
                break;
            }
        }
        if (flag) puts("YES"); else puts("NO");
    }
    return 0;
}