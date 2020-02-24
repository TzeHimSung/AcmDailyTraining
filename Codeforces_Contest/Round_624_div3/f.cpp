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

const int maxn = 2e5 + 10;
struct Point {
    int pos, val;
    bool operator<(const Point &rhs)const {
        return val < rhs.val;
    }
} a[maxn], l[maxn], r[maxn];
int n, p = 0, q = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].pos);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].val);
    for (int i = 1; i <= n; i++) {
        if (a[i].val > 0) {
            p++;
            l[p].pos = a[i].pos, l[p].val = a[i].val;
        }
        if (a[i].val < 0) {
            q++;
            r[q].pos = a[i].pos, r[q].val = a[i].val;
        }
    }
    sort(l + 1, l + 1 + p);
    sort(r + 1, r + 1 + q);

    return 0;
}