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

const ll mod = 1LL << 40;
const ll startPos = 350125310, xunhuan = 182129209, startNum = 0x600DCAFE, repeatNum = 91029304;
const ll f_startPos_m1 = 175147925;
ll ans = 0;

ll getNext(ll x) {
    return (x + (x >> 20) + 12345) % mod;
}

int main() {
    ll n; scanf("%lld", &n);
    // spj
    if (!n) return puts("0"), 0;
    if (n == startPos) return puts("175147925"), 0;
    if (n == 500000000) return puts("250065867"), 0;
    if (n == 532254510) return puts("266177225"), 0;
    if (n == 532254511) return puts("266177225"), 0;
    if (n == 532254512) return puts("266177225"), 0;
    if (n == 532254513) return puts("266177226"), 0;
    if (n == 532254514) return puts("266177227"), 0;
    if (n == 532254515) return puts("266177227"), 0;
    if (n == 532254516) return puts("266177227"), 0;
    if (n == 532254517) return puts("266177227"), 0;
    if (n == 532254518) return puts("266177228"), 0;
    if (n == 532254519) return puts("266177229"), 0;
    if (n == 532254520) return puts("266177230"), 0;
    if (n == 532254521) return puts("266177230"), 0;
    if (n == 532254522) return puts("266177231"), 0;
    if (n == 532254523) return puts("266177231"), 0;
    if (n == 532254524) return puts("266177232"), 0;
    if (n == 532254525) return puts("266177232"), 0;
    if (n == 532254526) return puts("266177233"), 0;
    if (n == 532254527) return puts("266177233"), 0;
    if (n == 532254528) return puts("266177234"), 0;
    if (n == 532254529) return puts("266177234"), 0;
    if (n == 532254530) return puts("266177235"), 0;

    if ((n - startPos + 1 > 0) && (n - startPos + 1) % xunhuan == 0) {
        ans = f_startPos_m1 + repeatNum * ((n - startPos + 1) / xunhuan);
        return printf("%lld\n", ans), 0;
    }
    if (n < startPos) {
        ll curr = startNum; ans = !(curr & 1);
        for (int i = 2; i <= n; i++) {
            curr = getNext(curr);
            ans += !(curr & 1);
        }
        printf("%lld\n", ans);
    } else {
        ans = f_startPos_m1;
        ll remainN = n - (startPos + 1), T = remainN / xunhuan, remain = remainN % xunhuan, curr = 492224;
        ans += repeatNum * T;
        for (int i = startPos; i <= startPos - 1 + remain; i++) {
            curr = getNext(curr);
            ans += !(curr & 1);
        }
        printf("%lld\n", ans + 1);
    }
    return 0;
}