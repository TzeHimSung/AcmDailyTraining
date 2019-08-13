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
    int t; scanf("%d", &t);
    while (t--) {
        ll n, m, k; scanf("%lld%lld%lld", &n, &m, &k);
        // m/(n-k+1)+1是前k-1题复习时间，m+1是第k题复习时间
        printf("%lld\n", (m / (n - k + 1) + 1) * (k - 1) + m + 1);
    }
    return 0;
}