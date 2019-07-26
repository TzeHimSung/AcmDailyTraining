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

const int maxn = 5e2 + 10;
int n, m, a[maxn][maxn], maxx[maxn], minn[maxn], q[maxn][2];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int ans = 1;
        scanf("%d%d", &n, &m);
        rep1(i, 1, n) {
            rep1(j, 1, n) scanf("%d", &a[i][j]);
        }
        rep1(i, 1, n) {
            rep1(j, 1, n) maxx[j] = -int_inf, minn[j] = int_inf;
            rep1(j, i, n) {
                // 维护第p列的极值
                rep1(p, 1, n) maxx[p] = max(maxx[p], a[j][p]);
                rep1(p, 1, n) minn[p] = min(minn[p], a[j][p]);
                int l = 1, h0 = 0, h1 = 0, t0 = 1, t1 = 1;
                rep1(r, 1, n) {
                    while (t0 <= h0 && maxx[r] >= maxx[q[h0][0]]) h0--;
                    while (t1 <= h1 && minn[r] <= minn[q[h1][1]]) h1--;
                    q[++h0][0] = q[++h1][1] = r;
                    while (l <= r && maxx[q[t0][0]] - minn[q[t1][1]] > m) {
                        l++;
                        if (q[t0][0] < l) t0++;
                        if (q[t1][1] < l) t1++;
                    }
                    ans = max(ans, (r - l + 1) * (j - i + 1));
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}