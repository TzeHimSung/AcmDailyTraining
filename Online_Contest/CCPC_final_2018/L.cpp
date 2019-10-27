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

bool check(ll x) {
    ll lim = (ll)sqrt(x);
    for (int i = 2; i <= lim; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve(ll x) {
    for (ll i = x - 2; i >= 2; i--) {
        if (check(i) && check(x - i)) {
            printf(" %lld %lld\n", i, x - i);
            return;
        }
    }
}

int main() {
    int T; scanf("%d", &T);
    int _case = 0;
    while (T--) {
        ll n; scanf("%lld", &n);
        printf("Case %d: ", ++_case);
        if (n <= 11) puts("IMPOSSIBLE");
        else {
            if (n % 2) {
                n -= 9;
                printf("2 2 2 3");
                solve(n);
            } else {
                n -= 8;
                printf("2 2 2 2");
                solve(n);
            }
        }
    }
    return 0;
}