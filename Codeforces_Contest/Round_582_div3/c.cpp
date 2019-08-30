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
    int q; scanf("%d", &q);
    while (q--) {
        ll n, m; scanf("%lld%lld", &n, &m);
        if (n < m) {
            puts("0");
            continue;
        }
        if (n == m) {
            printf("%lld\n", m % 10);
            continue;
        }
        ll len = n / m, tmp = m, sum = 0;
        set<int>s; s.clear();
        while (!s.count(tmp % 10)) {
            s.insert(tmp % 10);
            tmp += m;
        }
        tmp -= m;
        for (auto i : s) sum += i;
        int round = s.size();
        sum = len / round * sum;
        for (ll i = len / round * tmp + m; i <= n; i += m) {
            sum += i % 10;
        }
        printf("%lld\n", sum);
    }
    return 0;
}
