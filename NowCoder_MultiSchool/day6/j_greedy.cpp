#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
ll c[M][M], d[M], sum[M], val[M], tem[M];
int t, n, m;
int pos(ll c[], int l, int r) {
    ll val = inf;
    int mini;
    for (int i = l; i <= r; i++) {
        if (c[i] <= val) {
            val = c[i];
            mini = i;
        }
    }
    return mini;
}
int main() {
    scanf("%d", &t);
    int cas = 0;
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)sum[i] = 0;
        for (int i = 1; i <= n; i++) {
            val[i] = inf;
            c[i][0] = 0;
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
        for (int i = 1; i <= m; i++)
            scanf("%lld", &d[i]), d[i] -= sum[i], d[i] += d[i - 1];
        ll ans = 0, temp, maxv;
        for (int i = 0; i <= m; i++) {
            temp = d[i];
            int cnt = 0;
            if (i != m) {
                ll minv;
                maxv = -inf;
                for (int j = 1; j <= n; j++) {
                    if (tem[j] <= i)tem[j] = pos(c[j], i + 1, m);
                    minv = c[j][tem[j]];
                    if (minv - c[j][i] < 0) {
                        maxv = max(maxv, minv - c[j][i]);
                        temp -= minv - c[j][i];
                        cnt++;
                    }
                }
            }
            if (cnt == n)temp += maxv;
            ans = max(ans, temp);
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
    return 0;
}