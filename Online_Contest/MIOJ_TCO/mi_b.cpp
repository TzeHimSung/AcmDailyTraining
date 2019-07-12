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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const ll mod = 1e9 + 7;
const int maxn = 1e3 + 10;

pair<ll, ll> a[maxn], reg[maxn];
ll cnt[maxn][maxn], s[maxn][maxn];
vector<ll>vx, vy;
int n, m;

inline ll cal(ll lx, ll ly, ll rx, ll ry) {
    return 1LL * abs(rx - lx) * abs(ry - ly) % mod;
}

inline ll qp(ll a, ll b) {
    ll res = 1LL;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

inline ll inv(ll a) {
    return qp(a, mod - 2);
}

inline void add(ll &a, const ll &b) {
    a += b;
    if (a >= mod) a -= mod;
}

int main() {
    cin >> n;
    rep1(i, 1, n) {
        cin >> a[i].first >> a[i].second;
        vx.pb(a[i].first); vy.pb(a[i].second);
    }
    sort(vx.begin(), vx.end());
    sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());
    rep1(i, 1, n) {
        reg[i].first = lower_bound(vx.begin(), vx.end(), a[i].first) - vx.begin();
        reg[i].second = lower_bound(vy.begin(), vy.end(), a[i].second) - vy.begin();
    }
    memset(cnt, 0, sizeof(cnt));
    rep1(i, 1, n) {
        rep1(j, i + 1, n) {
            int lx = min(reg[i].first, reg[j].first);
            int rx = max(reg[i].first, reg[j].first);
            int ly = min(reg[i].second, reg[j].second);
            int ry = max(reg[i].second, reg[j].second);
            cnt[lx][ly]++; cnt[rx][ry]++;
            cnt[lx][ry]--; cnt[rx][ly]--;
        }
    }
    rep0(i, 1, vy.size()) add(cnt[0][i], cnt[0][i - 1]);
    rep1(i, 1, vx.size()) {
        add(cnt[i][0], cnt[i - 1][0]);
        rep1(j, 1, vy.size()) {
            add(cnt[i][j], cnt[i - 1][j]);
            add(cnt[i][j], cnt[i][j - 1]);
            add(cnt[i][j], mod - cnt[i - 1][j - 1]);
        }
    }
    ll fm = n * (n - 1) / 2, ans = 0LL;
    fm = inv(fm * (fm - 1) % mod);
    rep0(i, 0, vx.size() - 1) {
        rep0(j, 0, vy.size() - 1)
        if (cnt[i][j] > 1LL) {
            ll tmp = cal(vx[i + 1], vy[j + 1], vx[i], vy[j]);
            ans = (ans + tmp * (1LL * cnt[i][j] * (cnt[i][j] - 1) % mod)) % mod;
        }
    }
    printf("%lld\n", ans * fm % mod);
    return 0;
}