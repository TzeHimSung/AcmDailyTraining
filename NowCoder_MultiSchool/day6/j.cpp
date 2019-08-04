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

const int maxn = 1e3 + 10;
ll c[maxn][maxn], d[maxn], sum[maxn], val[maxn], tem[maxn];
int n, m;

int pos(ll *c, int l, int r) {
    ll val = ll_inf; int minI;
    for (int i = l; i <= r; i++)
        if (c[i] <= val) {
            val = c[i];
            minI = i;
        }
    return minI;
}

int main() {
    int t; scanf("%d", &t);
    for (int casenum = 1; casenum <= t; casenum++) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) sum[i] = 0;
        for (int i = 1; i <= n; i++) {
            c[i][0] = 0; val[i] = ll_inf;
            for (int j = 1; j <= m; j++) {
                scanf("%lld", &c[i][j]);
                sum[j] += c[i][j];
                c[i][j] += c[i][j - 1];
                if (c[i][j] <= val[i]) {
                    val[i] = c[i][j];
                    tem[i] = j;
                }
            }
        }
        d[0] = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%lld", &d[i]);
            d[i] -= sum[i]; d[i] += d[i - 1];
        }
        ll ans = 0, tmp, maxv;
        for (int i = 0; i <= m; i++) {
            tmp = d[i]; int cnt = 0;
            if (i != m) {
                ll minv; maxv = -ll_inf;
                for (int j = 1; j <= n; j++) {
                    if (tem[j] <= i) tem[j] = pos(c[j], i + 1, m);
                    minv = c[j][tem[j]];
                    if (minv - c[j][i] < 0) {
                        maxv = max(maxv, minv - c[j][i]);
                        tmp -= minv - c[j][i];
                        cnt++;
                    }
                }
            }
            if (cnt == n) tmp += maxv;
            ans = max(ans, tmp);
        }
        printf("Case #%d: %lld\n", casenum, ans);
    }
    return 0;
}