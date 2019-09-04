/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define ull unsigned long long
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

ull lowbit(ull x) {
    return x & -x;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ull a, b; scanf("%lld%lld", &a, &b);
        printf("%lld\n", !(a & b) ? lowbit(a | b) : (a & b));
    }
    return 0;
}
