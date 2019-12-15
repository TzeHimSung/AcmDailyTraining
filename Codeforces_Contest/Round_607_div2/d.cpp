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

const int maxn = 100;
int t, n, m;
char a[maxn][maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        int foundA = 0, foundP = 0, ans = 4;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", a[i] + 1);
            for (int j = 1; j <= m; j++)
                if (a[i][j] == 'A') foundA = 1;
                else foundP = 1;
        }
        if (!foundA) {
            puts("MORTAL");
            continue;
        }
        if (!foundP) {
            puts("0");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            int maxx = -1, minn = 1000;
            for (int j = 1; j <= m; j++) {
                maxx = max(maxx, (int)a[i][j]), minn = min(minn, (int)a[i][j]);
                if (a[i][j] == 'A') {
                    int t = 4;
                    if (i == 1 || i == n) t--;
                    if (j == 1 || j == m) t--;
                    ans = min(ans, t);
                }
            }
            if (maxx == minn && maxx == 'A') {
                if (i == 1 || i == n) ans = min(ans, 1);
                else ans = min(ans, 2);
            }
        }
        for (int j = 1; j <= m; j++) {
            int maxx = -1, minn = 1000;
            for (int i = 1; i <= n; i++) {
                maxx = max(maxx, (int)a[i][j]), minn = min(minn, (int)a[i][j]);
            }
            if (maxx == minn && maxx == 'A') {
                if (j == 1 || j == m) ans = min(ans, 1);
                else ans = min(ans, 2);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
