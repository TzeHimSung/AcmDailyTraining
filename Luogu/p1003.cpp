/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e4 + 10;
struct Ditan {
    int x, y, a, b;
} a[maxn];
int p, q, ans = -1, n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].a, &a[i].b);
    scanf("%d%d", &p, &q);
    for (int i = 0; i < n; i++) {
        if (a[i].x <= p && p <= a[i].x + a[i].a && a[i].y <= q && q <= a[i].y + a[i].b) ans = i + 1;
    }
    printf("%d\n", ans);
    return 0;
}