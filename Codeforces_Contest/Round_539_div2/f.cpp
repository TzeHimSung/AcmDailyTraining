/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <climits>
#include <float.h>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int mod = 1e9 + 7;
const int maxn = 1e6 + 10;
ll fac[maxn], inv[maxn], pown[maxn], powm[maxn], ans = 0;
int n, m, a, b;

ll quick_mod(ll a, ll b) {
    a %= mod, b %= mod;
    ll ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

ll A(int p, int q) {
    if (p - q < 0 || p < 0)
        return 0;
    return fac[p] * inv[p - q] % mod;
}

ll C(int p, int q) {
    if (p - q < 0 || p < 0 || q < 0)
        return 0;
    return fac[p] * inv[q] % mod * inv[p - q] % mod;
}

int main() {
    cin >> n >> m >> a >> b;
    int tmp = max(n, m);
    fac[0] = fac[1] = 1;
    rep1(i, 2, tmp) fac[i] = fac[i - 1] * i % mod;
    inv[tmp] = quick_mod(fac[tmp], mod - 2);
    for (int i = tmp; i >= 1; i--)
        inv[i - 1] = inv[i] * i % mod;
    pown[0] = powm[0] = 1;
    rep1(i, 1, tmp) {
        powm[i] = powm[i - 1] * m % mod;
        pown[i] = pown[i - 1] * n % mod;
    }
    rep1(i, 1, n - 1) {
        ll mul = A(n - 2, i - 1) * C(m - 1, i - 1) % mod * powm[n - i - 1] % mod;
        if (n - i - 2 >= 0)
            mul = mul * (i + 1) % mod * pown[n - i - 2] % mod;
        ans = (ans + mul) % mod;
    }
    cout << ans << endl;
    return 0;
}