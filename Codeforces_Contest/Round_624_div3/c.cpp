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

const int maxn = 2e5 + 10;
int t, n, m, p[maxn], cnt[maxn][26], ans[26];
char s[maxn];

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        scanf("%s", s + 1);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 26; j++)
                cnt[i][j] = 0;
        for (int i = 0; i < 26; i++) ans[i] = 0;
        for (int i = 1; i <= m; i++) scanf("%d", &p[i]);

        for (int i = 1; i <= n; i++) {
            cnt[i][s[i] - 'a']++;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 26; j++) {
                cnt[i][j] += cnt[i - 1][j];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < 26; j++) {
                ans[j] += cnt[p[i]][j];
            }
        }
        for (int i = 0; i < 26; i++) ans[i] += cnt[n][i];
        for (int i = 0; i < 26; i++) printf("%d ", ans[i]);
        puts("");
    }
    return 0;
}