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

int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        ll n, m; scanf("%lld%lld", &n, &m);
        if (!m) {
            puts("0");
            continue;
        }
        ll ans = (1 + n) * n / 2;
        if (m <= n / 2) {
            ll chu = (n - m) / (m + 1), remain = (n - m) % (m + 1);
            ans -= (chu + 1) * (chu + 2) * remain / 2;
            ans -= (chu + 1) * (m + 1 - remain) * chu / 2;
        } else ans -= n - m;
        printf("%lld\n", ans);
    }
    return 0;
}
/*
1 0 0
1 1 1

2 0 0
2 1 2
2 2 3

3 0 0
3 1 4
3 2 5
3 3 6

4 0 0
4 1 5
4 2 8
4 3 9
4 4 10

5 0 0
5 1 6
5 2 12
5 3 13
5 4 14
5 5 15

6 0 0
6 1 7
6 2 17
6 3 18
6 4 19
6 5 20
6 6 21

7 0 0
7 1 8
7 2 23
7 3 24
7 4 25
7 5 26
7 6 27
7 7 28
 */