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

const int maxn = 60;
int a[maxn], now[maxn], ans = 0, n, m;

int main() {
    scanf("%d%d", &n, &m);
    rep1(i, 1, n) scanf("%d", &a[i]);
    for (int i = 1; i <= min(n, m); i++) {
        rep1(j, 0, i) {
            rep1(k, 0, n) now[k] = 0;
            int cnt = 0;
            rep1(k, 1, i - j) now[++cnt] = a[k];
            rep1(k, 1, j) now[++cnt] = a[n - k + 1];
            sot(now, i);
            int tot = m - i, sum = 0, x = 1;
            while (tot && now[x] < 0) x++, tot--;
            for (; x <= i; x++) sum += now[x];
            ans = max(ans, sum);
        }
    }
    printf("%d\n", ans);
    return 0;
}