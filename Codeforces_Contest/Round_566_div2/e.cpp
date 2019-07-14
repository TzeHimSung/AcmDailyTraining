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

const ll mod = 1e9 + 7, MOD = 1000000006;
const int maxn = 3;

struct Matrix {
    ll mat[8][8];
};

ll n, f1, f2, f3, c, ans = 1;
Matrix ma;

// matrix multiply
Matrix mat_mul(Matrix a, Matrix b) {
    Matrix ret;
    for ( int i = 1; i <= maxn; i++ )
        for ( int j = 1; j <= maxn; j++ )
            ret.mat[i][j] = 0;
    for ( int i = 1; i <= maxn; i++ )
        for ( int j = 1; j <= maxn; j++ )
            for ( int k = 1; k <= maxn; k++ )
                ret.mat[i][j] = ( ret.mat[i][j] + a.mat[i][k] * b.mat[k][j] % MOD ) % MOD;
    return ret;
}

// matrix quick pow
Matrix mat_pow(Matrix a, ll b) {
    Matrix ret;
    memset(ret.mat, 0, sizeof(ret.mat));
    for (int i = 1; i <= maxn; i++)
        ret.mat[i][i] = 1;
    while (b > 0) {
        if (b & 1)
            ret = mat_mul(ret, a);
        a = mat_mul(a, a);
        b >>= 1;
    }
    return ret;
}

// quick pow
ll pow_mod(ll x, ll b) {
    ll ret = 1;
    while (b > 0) {
        if (b & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    cin >> n >> f1 >> f2 >> f3 >> c;
    ll inv = pow_mod(c, mod - 2);
    memset(ma.mat, 0, sizeof(ma.mat));
    ma.mat[1][1] = ma.mat[1][2] = ma.mat[1][3] = ma.mat[2][1] = ma.mat[3][2] = 1;
    ma = mat_pow(ma, n - 3);
    f1 = f1 * c % mod;
    f2 = f2 * c % mod * c % mod;
    f3 = f3 * c % mod * c % mod * c % mod;
    ans = pow_mod(f1, ma.mat[1][3]) * pow_mod(f2, ma.mat[1][2]) % mod * pow_mod(f3, ma.mat[1][1]) % mod;
    ans = ans * pow_mod(inv, n) % mod;
    cout << ans << endl;
    return 0;
}