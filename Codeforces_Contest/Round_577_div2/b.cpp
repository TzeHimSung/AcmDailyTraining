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

int x, n, maxx = 0;
ll sum = 0;

int main() {
    scanf("%d", &n);
    rep1(i, 1, n) {
        int x; scanf("%d", &x);
        maxx = max(maxx, x);
        sum += x;
    }
    if (sum < maxx * 2 || sum & 1) puts("NO");
    else puts("YES");
    return 0;
}