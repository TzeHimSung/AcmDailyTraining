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

const int maxn = 1e6 + 10;
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = n - 1; i >= 1; i--) {
        if (a[i] > a[i + 1]) {
            int r = i + 1;
            while (r < n && a[r] == a[r + 1]) r++;
            for (int i = 1; i <= r; i++) {
                if (a[i] > a[r]) {
                    int l = i;
                    reverse(a  + l, a + 1 + r);
                    int flag = 1;
                    for (int i = 1; i < n; i++) if (a[i] > a[i + 1]) flag = 0;
                    if (flag) return printf("%d %d\n", l, r), 0;
                    else return puts("impossible"), 0;
                }
            }
        }
    }
    puts("1 1");
    return 0;
}