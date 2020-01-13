#include<iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;
#define ll long long

ll M, N, mod, p[100], tot, num[100], cnt[100], ap[100], P[16000010], mu[16000010], cntt;
bool vis[16000010];
vector<int> factor;
unordered_map<ll, ll> mp2;
ll fuck_dp[16000010];

ll mypow(ll a, ll b) {
    ll ret = 1;
    while (b) {
        if (b & 1)ret = ret * a % mod;
        a = a * a % mod; b >>= 1;
    }
    return ret;
}

void init() {
    mu[1] = 1;
    for (int i = 2; i < 16000010; i++) {
        if (!vis[i])P[cntt++] = i, mu[i] = -1;
        for (int j = 0; j < cntt && P[j]*i < 16000010; j++) {

            int now = P[j] * i;
            vis[now] = 1;
            if (i % P[j] == 0) {
                mu[now] = 0;
                break;
            } else mu[now] = -mu[i];
        }
    }
}

void exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0)x = 1, y = 0;
    else {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

ll inv(ll a) {
    ll x, y;
    exgcd(a, mod, x, y);
    return x < 0 ? x + mod : x;
}

void fuck_init() {
    fuck_dp[0] = 1;
    for (int i = 1; i <= mod; i++) {
        int tmp = i;
        for (int i = 1; i <= tot; i++) {
            if (tmp % p[i] == 0) {
                tmp = 1;
                break;
            }
        }
        fuck_dp[i] = fuck_dp[i - 1] * tmp % mod;
    }
}

inline ll calcu(int n) {
    return fuck_dp[n];
}

ll calcu2(ll n) {
    if (n == 0)return 1;
    if (mp2[n])return mp2[n];
    ll ret = mypow(calcu(mod - 1), n / mod) * calcu(n % mod) % mod;
    for (auto &it : factor) {

        ll tmp = calcu2(n / it);
        ret = ret * (mu[it] == 0 ? 1 : (mu[it] == -1 ? tmp : inv(tmp))) % mod;
    }
    return mp2[n] = ret;
}

ll calcu3(ll n, ll x) {
    ll ret = 0, base = x;
    while (x <= n) {
        ret += n / x;
        if (x > n / base)break;
        x *= base;
    }
    return ret;
}

int main() {
    init();
    cin >> M >> N >> mod;
    int D = mod;
    for (int i = 2; i * i <= D; i++) {
        if (D % i == 0) {
            int tmp = 0;
            while (D % i == 0) {
                tmp++;
                D /= i;
            }
            p[++tot] = i;
            num[tot] = tmp;
        }
    }
    if (D >= 2) {
        p[++tot] = D;
        num[tot] = 1;
    }
    for (int i = 2; i <= mod; i++) if (mod % i == 0) factor.push_back(i);
    fuck_init();
    ll ans = calcu2(M);
    ll ans2 = calcu2(N);
    ll ans3 = calcu2(M - N);
    for (int i = 1; i < mod; i++) {
        if (ans2 * i % mod == 1) ans = ans * i % mod;
        if (ans3 * i % mod == 1) ans = ans * i % mod;
    }
    ll minn = 9e18;
    for (int i = 1; i <= tot; i++) {
        cnt[i] += calcu3(M, p[i]);
        cnt[i] -= calcu3(N, p[i]) + calcu3(M - N, p[i]);
        ap[i] = cnt[i] / num[i];
        minn = min(minn, ap[i]);
    }
    for (int i = 1; i <= tot; i++) cnt[i] -= minn * num[i];
    ll anss = 1;
    for (int i = 1; i <= tot; i++) anss = anss * mypow(p[i], cnt[i]) % mod;
    cout << ans *anss % mod << endl;
}