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

const ll m = 1e5, maxn = 1e6 + 10;
ll a[maxn][10], ans[10][maxn], cnt[10];

bool check(ll x, ll y) {
    if (x < 0 && y >= 0) return 1;
    if (x > y && x >= 0 && x < m) return 1;
    return 0;
}

int main() {
    for (int i = 1; i < m * 10; i++) {
        for (int j = 0; j < 10; j++) a[i][j] = a[i / 10][j];
        a[i][i % 10]++;
    }
    for (int d = 1; d < 10; d++) {
        int r = 1;
        for (int i = 0; i < m * d; i++)
            if (check(r, r - m / 2 + m * a[i][d])) {
                for (int j = 0; j < m; j++) {
                    r += a[i][d] + a[j][d] - 1;
                    if (!r) ans[d][cnt[d]++] = m * i + j;
                }
            } else r += m * a[i][d] - m / 2;
    }
    int query; scanf("%d", &query);
    while (query--) {
        int d; ll k; scanf("%d%lld", &d, &k);
        int r = cnt[d] - 1;
        while (r >= 0 && ans[d][r] > k) r--;
        if (r >= 0) printf("%lld\n", ans[d][r]);
        else puts("0");
    }
    return 0;
}