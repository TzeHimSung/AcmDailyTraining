/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int MAXN = 555;
int n, m, ans = 0;
char a[MAXN][MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    if (n == 1) {
        for (int i = 2; i < m; i++) {
            if (a[1][i] == '.') ans++;
        }
        printf("%d\n", ans);
    } else if (n == 2) {
        for (int i = 2; i < m; i++) {
            if (a[1][i] == '.' && a[1][i] == a[2][i]) ans++;
        }
        printf("%d\n", ans);
    } else if (m == 1) {
        for (int i = 2; i < n; i++) {
            if (a[i][1] == '.') ans++;
        }
        printf("%d\n", ans);
    } else if (m == 2) {
        for (int i = 2; i < n; i++) {
            if (a[i][1] == '.' && a[i][1] == a[i][2]) ans++;
        }
        printf("%d\n", ans);
    } else {
        int tmp = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if ((i == 1 || i == n) && (j == 1 || j == m)) continue;
                else if (i == 1 || i == n || j == 1 || j == m) {
                    if (a[i][j] == '#') tmp = 0;
                } else if (a[i][j] == '.') ans++;
            }
        }
        printf("%d\n", ans + tmp);
    }
    return 0;
}