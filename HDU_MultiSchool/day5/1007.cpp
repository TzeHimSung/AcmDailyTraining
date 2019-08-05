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

const int maxn = 1e5 + 10, mod = 998244353;
int t, a[maxn];

int main() {
    a[1] = 0, a[2] = 1, a[3] = 1;
    for (int i = 4; i < maxn; i++) a[i] = (a[i - 1] + a[i - 3]) % mod;
    scanf("%d", &t);
    while (t--) {
        int n, x, y; scanf("%d%d%d", &n, &x, &y);
        if (x > y) swap(x, y);
        int fixY = x != 1 ? y - x : y;
        if (y != n) printf("%d\n", a[fixY]); else printf("%d\n", a[fixY + 1]);
    }
    return 0;
}