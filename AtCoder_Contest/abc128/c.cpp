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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 15;
int n, m, p[maxn], ans = 0, a[maxn][maxn];

int main() {
    scanf("%d%d", &n, &m);
    rep1(i, 1, m) {
        scanf("%d", &a[i][0]);
        rep1(j, 1, a[i][0]) scanf("%d", &a[i][j]);
    }
    rep1(i, 1, m) scanf("%d", &p[i]);
    rep1(i, 0, (1 << n) - 1) {
        int flag = 1, cmp = i, swit[20], light[20], cnt = 0;
        rep1(i, 1, 20) swit[i] = light[i] = 0;
        while (cmp) swit[++cnt] = cmp & 1, cmp >>= 1;
        rep1(i, 1, m)
        rep1(j, 1, a[i][0]) light[i] += swit[a[i][j]];
        rep1(i, 1, m) if ((light[i] % 2) != p[i]) {
            flag = 0; break;
        }
        if (flag) ans++;
    }
    printf("%d\n", ans);
    return 0;
}