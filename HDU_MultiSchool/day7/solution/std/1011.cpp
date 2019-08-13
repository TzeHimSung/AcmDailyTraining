#include <iostream>

using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int MAXN = 1e6 + 7;
int sum[MAXN];

int qp(ll a, int n) {
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

int main() {
    int cas, n, q, l, r, p, q, a, x;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d%d", &p, &q, &x, &a);
            ll tmp = (sum[i - 1] - sum[x - 1] + mod) % mod;
            sum[i] = (tmp + a) % mod * q % mod * qp(p, mod - 2) % mod;
            sum[i] = (sum[i] - tmp + mod) % mod;
            sum[i] = (sum[i - 1] + sum[i]) % mod;
        }
        while (q--) {
            scanf("%d%d", &l, &r);
            printf("%d\n", (sum[r - 1] - sum[l - 1] + mod) % mod);
        }
    }
}