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

const int maxn = 4e5 + 10;
int a[maxn], n;

int main() {
    scanf("%d", &n);
    ll gcd = 1, k; scanf("%lld", &k);
    gcd = k;
    for (int i = 1; i < n; i++) {
        ll x; scanf("%lld", &x);
        gcd = __gcd(gcd, x);
    }
    if (gcd == 1) return puts("1"), 0;
    int cnt = 0;
    for (ll i = 1; i < sqrt(gcd); i++)
        if (gcd % i == 0) cnt += 2;
    ll tmp = sqrt(gcd);
    if (tmp * tmp == gcd) cnt++;
    printf("%d\n", cnt);
    return 0;
}