/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const ll mod = 1e9 + 7, maxn = 1e6 + 10;
ll ans = 1, fac[maxn << 1], cartlan[maxn];
unordered_map<ll, ll>m; // m维护的是次数的次数，方便后续计算
stack<ll>st;
int n;

ll qp(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}

void init() {
    m.clear();
    while (st.size()) st.pop();
    fac[0] = 1;
    for (ll i = 1; i < (maxn << 1); i++) fac[i] = i * fac[i - 1] % mod;
    for (ll i = 1; i < maxn; i++) cartlan[i] = fac[i << 1] * qp(fac[i], mod - 2) % mod * qp(fac[i], mod - 2) % mod * qp(i + 1, mod - 2) % mod;
}

int main() {
    init();
    scanf("%d", &n);
    while (n--) {
        ll x; scanf("%lld", &x);
        ll currElement = x, cnt = 0;
        while ((int)st.size() && x < st.top()) {
            if (st.top() == currElement) cnt++;
            else {
                if (cnt >= 2) m[cnt]++;
                currElement = st.top(), cnt = 1;
            }
            st.pop();
        }
        if (cnt >= 2) m[cnt]++;
        st.push(x);
    }
    ll currElement = -1, cnt = 0;
    while ((int)st.size() && -1 < st.top()) {
        if (st.top() == currElement) cnt++;
        else {
            if (cnt >= 2) m[cnt]++;
            currElement = st.top(), cnt = 1;
        }
        st.pop();
    }
    if (cnt >= 2) m[cnt]++;

    for (auto i : m) {
        ll t = qp(cartlan[i.first], i.second);
        ans = (ans * t) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}