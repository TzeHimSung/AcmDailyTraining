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

const int maxn = 15;
int m[maxn], t[maxn], n, m;
pair<int, int>p[maxn];

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!a && !b) return -1;
    if (!b) {
        x = 1, y = 0; return a;
    }
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int solve(int &m0, int &a0, int m, int a) {
    ll x, y;
    int g = exgcd(m0, m, x, y);
    if (abs(a - a0) % g) return 0;
    x *= (a - a0) / g; x %= m / g;
    a0 = x * m0 + a0; m0 *= m / g; a0 %= m0;
    if (a0 < 0) a0 += m0;
    return 1;
}

int MLES(int &m0, int &a0, int n) {
    int flag = 1; m0 = 1, a0 = 0;
    rep0(i, 0, n)
    if (!solve(m0, a0, m[i], t[i])) {
        flag = 0;
        break;
    }
    return flag;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        rep1(i, 1, n) scanf("%d%d%d%d", &p[i].first, &p[i].second, &m[i], &t[i]);
        if (MLES(m[1], t[1], n)) {
            int tt = 0;
            while (tt * m[1] + a[1] <= m) {
                int curr = tt * m[1] + a[1];
                tt++;
            }
        } else puts("0");
    }
    return 0;
}