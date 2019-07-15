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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m, ans = int_inf; cin >> n >> m;
        char s[n + 1][m + 1];
        int row[n + 1] = {0}, col[m + 1] = {0};
        rep1(i, 1, n) {
            scanf("%s", s[i] + 1);
            rep1(j, 1, m) {
                if (s[i][j] == '.') row[i]++, col[j]++;
            }
        }
        rep1(i, 1, n) {
            rep1(j, 1, m) {
                int k = row[i] + col[j];
                if (s[i][j] == '.') k--;
                ans = min(ans, k);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}