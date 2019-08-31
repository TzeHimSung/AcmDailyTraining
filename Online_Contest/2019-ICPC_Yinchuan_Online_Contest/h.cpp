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

const int maxn = 1e5 + 10;
struct Monster {
    int hp, atk;
    Monster() {}

    bool operator<(const Monster &rhs)const {
        ll x = ceil((sqrt(1.0 + 8.0 * hp) - 1) / 2.0);
        ll y = ceil((sqrt(1.0 + 8.0 * rhs.hp) - 1) / 2.0);
        if ((ll)atk * y == (ll)rhs.atk * x)
            return atk > rhs.atk;
        return atk * y > rhs.atk * x;
    }
} m[maxn];
ll sum[maxn];

int main() {
    int t; scanf("%d", &t);
    for (int __ = 1; __ <= t; __++) {
        ll ans = 0, turn = 0;
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d%d", &m[i].hp, &m[i].atk);
        sort(m, m + n);
        for (int i = 0; i <= n + 1; i++) sum[i] = 0;
        for (int i = n - 1; i >= 0; i--)
            sum[i] += sum[i + 1] + m[i].atk;
        for (int i = 0; i < n; i++) {
            turn = (ll)ceil((sqrt(1.0 + 8.0 * m[i].hp) - 1) / 2.0);
            ans += sum[i] * turn;
        }
        printf("Case #%d: %lld\n", __, ans);
    }
    return 0;
}

