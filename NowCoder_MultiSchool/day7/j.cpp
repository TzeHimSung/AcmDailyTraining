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

ll f(ll x) {
    vector<int>v; v.clear();
    while (x) {
        v.pb(x % 10); x /= 10;
    }
    int _size = v.size();
    ll ret = 0;
    for (int i = 0; i < _size; i++) ret = ret * 10 + v[i];
    return ret;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll a, b; scanf("%lld%lld", &a, &b);
        printf("%lld\n", f(f(a) + f(b)));
    }
    return 0;
}