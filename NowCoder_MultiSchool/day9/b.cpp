#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;


typedef long long ll;

const ll MOD = 1000000007;
long long mod_exp(long long a, long long b) { //二分快速幂
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

long long solve(long long n, long long p) {
    int Q = p - 1, S = 0;
    while (Q % 2 == 0) {
        Q >>= 1;
        S++;
    }
    if (S == 1) {
        return mod_exp(n, (p + 1) / 4);
    }
    int z;
    while (1) {
        z = 1 + rand() % (p - 1);
        if (mod_exp(z, (p - 1) / 2) != 1) break;
    }
    long long c = mod_exp(z, Q);
    long long R = mod_exp(n, (Q + 1) / 2);
    long long t = mod_exp(n, Q);
    long long M = S, b, i;
    while (1) {
        if (t % p == 1) break;
        for (i = 1; i < M; i++) {
            if (mod_exp(t, 1 << i) == 1) break;
        }
        b = mod_exp(c, 1 << (M - i - 1));
        R = (R * b) % p;
        t = (t * b * b) % p;
        c = (b * b) % p;
        M = i;
    }
    return (R % p + p) % p;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll b, c;
        cin >> b >> c;
        ll dex = b * b - 4 * c;
        dex = (dex + MOD) % MOD;
        if (dex == 0) {
            ll x1 = b * mod_exp(2, MOD - 2) % MOD;
            cout << x1 << " " << x1 << endl;
            continue;
        }
        if (mod_exp(dex, (MOD - 1) / 2) != 1) {
            cout << "-1 -1" << endl;
            continue;
        }
        ll rx = solve(dex, MOD);
        ll x1 = (rx + b) * mod_exp(2, MOD - 2) % MOD;
        ll x2 = (b - x1 + MOD) % MOD;
        cout << min(x1, x2) << " " << max(x1, x2) << endl;
    }
}