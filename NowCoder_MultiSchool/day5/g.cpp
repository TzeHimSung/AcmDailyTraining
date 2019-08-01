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

const int mod = 998244353, maxn = 3e3 + 10;
int inv[maxn], fac[maxn], fiv[maxn], dp[2][maxn];

int add(int a, int b) {
    return a + b < mod ? a + b : a + b - mod;
}

int mul(int a, int b) {
    return (ll)a * b % mod;
}

int C(int n, int m) {
    return n < m ? 0 : mul(fac[n], mul(fiv[m], fiv[n - m]));
}

int main() {
    inv[0] = inv[1] = fac[0] = fac[1] = fiv[0] = fiv[1] = 1;
    for (int i = 2; i < maxn; i++) {
        inv[i] = mul(inv[mod % i], mod - mod / i);
        fac[i] = mul(fac[i - 1], i);
        fiv[i] = mul(fiv[i - 1], inv[i]);
    }
    dp[0][0] = 1;
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; char s[maxn], t[maxn];
        scanf("%d%d", &n, &m); cin >> s >> t;
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (s[i] != '0') {
                for (int j = m; i + j < n; j++)
                    ans = add(ans, C(n - i - 1, j));
            }
        int *dp0 = dp[0], *dp1 = dp[1];
        size_t size = (m + 1) << 2;
        memset(dp0, 0, size);
        for (int i = 1; i <= n; i++) {
            memcpy(dp1, dp0, size);
            for (int j = 1; j <= m; j++) {
                // 要拿当前位
                if (s[n - i] > t[m - j]) dp1[j] = add(dp1[j], C(i - 1, j - 1));
                // 不拿当前位
                if (s[n - i] == t[m - j]) dp1[j] = add(dp1[j], dp0[j - 1]);
            }
            swap(dp0, dp1);
        }
        printf("%d\n", add(ans, dp0[m]));
    }
    return 0;
}