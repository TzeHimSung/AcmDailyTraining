#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll mod = 1000000007;
const int MAXN = 1005;

int n, m;
typedef pair<ll, ll> P;
P a[MAXN];
P aid[MAXN];
inline ll cal(ll lx, ll ly, ll rx, ll ry) {
    return 1ll * abs(rx - lx) * abs(ry - ly) % mod;
}
inline ll poww(ll a, ll b) {
    ll res = 1ll;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod; b >>= 1;
    } return res;
}
inline ll inv(ll a) {
    return poww(a, mod - 2);
}
ll cc[MAXN][MAXN];
ll S[MAXN][MAXN];
vector<ll>vx, vy;
inline void add(ll &a, const ll &b) {
    a += b; if (a >= mod) a -= mod;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        vx.push_back(a[i].first);
        vy.push_back(a[i].second);
    }
    sort(vx.begin(), vx.end()); vx.erase(unique(vx.begin(), vx.end()), vx.end());
    sort(vy.begin(), vy.end()); vy.erase(unique(vy.begin(), vy.end()), vy.end());
    for (int i = 1; i <= n; i++) {
        aid[i].first = lower_bound(vx.begin(), vx.end(), a[i].first) - vx.begin();
        aid[i].second = lower_bound(vy.begin(), vy.end(), a[i].second) - vy.begin();
    }
    memset(cc, 0, sizeof cc);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            int lx = min(aid[i].first, aid[j].first);
            int rx = max(aid[i].first, aid[j].first);
            int ly = min(aid[i].second, aid[j].second);
            int ry = max(aid[i].second, aid[j].second);
            cc[lx][ly]++; cc[rx][ry]++;
            cc[lx][ry]--; cc[rx][ly]--;
        }
    for (int i = 1; i < vy.size(); i++)
        add(cc[0][i], cc[0][i - 1]);
    for (int i = 1; i <= vx.size(); i++) {
        add(cc[i][0], cc[i - 1][0]);
        for (int j = 1; j <= vy.size(); j++) {
            add(cc[i][j], cc[i - 1][j]);
            add(cc[i][j], cc[i][j - 1]);
            add(cc[i][j], mod - cc[i - 1][j - 1]);
        }
    }
    ll fm = n * (n - 1) / 2;
    fm = inv(fm * (fm - 1) % mod);
    ll ans = 0ll;
    for (int i = 0; i < vx.size() - 1; i++) {
        for (int j = 0; j < vy.size() - 1; j++) {
            if (cc[i][j] > 1ll) {
                ll SS = cal(vx[i + 1], vy[j + 1], vx[i], vy[j]);
                ans = (ans + SS * (1ll * cc[i][j] * (cc[i][j] - 1) % mod)) % mod;
            }
        }
    }
    printf("%lld\n", ans * fm % mod);
    return 0;
}