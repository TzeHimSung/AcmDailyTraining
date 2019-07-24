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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int mod = 1e6 + 3;
ll p[mod + 10];
int n;

int main() {
    p[0] = p[1] = 1;
    rep0(i, 2, mod) p[i] = 1ll * i * p[i - 1] % mod;
    while (~scanf("%d", &n)) {
        if (n >= mod) {
            puts("0");
            continue;
        }
        n %= mod;
        printf("%lld\n", p[n]);
    }
    return 0;
}