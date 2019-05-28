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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

int calc(ll x) {
    if (x < 10) return x;
    int a[20]; a[0] = 0;
    while (x) a[++a[0]] = x % 10, x /= 10;
    ll tmp = 0;
    for (int i = a[0]; i >= 2; i--) tmp = tmp * 10 + (a[i] + a[i - 1]) % 10;
    return calc(tmp);
}

ll solve(ll x) {
    ll ret = (x + 1) / 10 * 45;
    if (x % 10 == 9) return ret;
    int y = calc(x / 10 * 10);
    rep1(i, 0, x % 10) ret += (y + i) % 10;
    return ret;
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll l, r; scanf("%lld%lld", &l, &r);
        printf("%lld\n", solve(r) - solve(l - 1));
    }
}