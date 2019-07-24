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

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int n, xl = -100000, xr = 100000, yu = 100000, yd = -100000;
        scanf("%d", &n);
        rep1(i, 1, n) {
            int x, y, f1, f2, f3, f4; scanf("%d%d%d%d%d%d", &x, &y, &f1, &f2, &f3, &f4); //zuo shang you xia
            if (f1 + f2 + f3 + f4 == 4) continue;
            if (!f1) xl = max(xl, x);
            if (!f2) yu = min(yu, y);
            if (!f3) xr = min(xr, x);
            if (!f4) yd = max(yd, y);
        }
        // ans
        if (xl <= xr && yu >= yd) printf("1 %d %d\n", xl, yd);
        else puts("0");
    }
    return 0;
}