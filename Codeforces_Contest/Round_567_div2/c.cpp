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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e3 + 10;
int n, m, a[maxn][maxn];
char s[maxn][maxn];
ll ans;

int main() {
    scanf("%d%d", &n, &m);
    rep1(i, 1, n) scanf("%s", s[i] + 1);
    rep1(j, 1, m) {
        for (int i = n; i; i--) {
            // a[i][j] means a[i][j] blocks' color are same with current one below, including current block
            if (s[i][j] != s[i + 1][j]) a[i][j] = 1;
            else a[i][j] = a[i + 1][j] + 1;
        }
    }
    rep1(i, 1, n) {
        rep1(j, 1, m) {
            int num = a[i][j];
            if (num * 3 + i - 1 > n) continue; // judge the length of the flag
            ll cnt = 0;
            // if current condition satisfly to form a flag
            while (a[i + num][j] == num && a[i + 2 * num][j] >= num) {
                cnt++; j++;
                if (a[i][j] != num) {
                    j--; break;
                }
                if (s[i][j] != s[i][j - 1]) {
                    j--; break;
                }
                if (s[i + num][j] != s[i + num][j - 1]) {
                    j--; break;
                }
                if (s[i + 2 * num][j] != s[i + 2 * num][j - 1]) {
                    j--; break;
                }
            }
            ans += (cnt + 1) * cnt / 2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}