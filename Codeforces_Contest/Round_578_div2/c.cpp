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

ll n, m;
int q;

int main() {
    scanf("%lld%lld%d", &n, &m, &q);
    ll gcd = __gcd(n, m);
    ll awall = n / gcd, bwall = m / gcd;
    while (q--) {
        ll x, y, p, q; scanf("%lld%lld%lld%lld", &x, &y, &p, &q);
        ll tmpa, tmpb;
        if (x == 1)
            tmpa = y % awall ? y / awall : y / awall - 1;
        else
            tmpa = y % bwall ? y / bwall : y / bwall - 1;
        if (p == 1)
            tmpb = q % awall ? q / awall : q / awall - 1;
        else
            tmpb = q % bwall ? q / bwall : q / bwall - 1;
        if (tmpa == tmpb) puts("YES"); else puts("NO");
    }
    return 0;
}