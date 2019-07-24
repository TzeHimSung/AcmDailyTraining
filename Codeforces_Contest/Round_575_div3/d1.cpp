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

const int maxn = 2e3 + 10;
char s[maxn];
map<char, char>m;

int main() {
    m['R'] = 'G'; m['G'] = 'B'; m['B'] = 'R';
    int q; scanf("%d", &q);
    while (q--) {
        int n, k, ans = int_inf; scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        for (int i = 1; i + k - 1 <= n; i++) {
            char curr = 'R'; int cnt = 0;
            rep1(j, i, i + k - 1) {
                if (s[j] != m[curr]) cnt++;
                curr = m[curr];
            }
            ans = min(ans, cnt);
            curr = 'G'; cnt = 0;
            rep1(j, i, i + k - 1) {
                if (s[j] != m[curr]) cnt++;
                curr = m[curr];
            }
            ans = min(ans, cnt);
            curr = 'B'; cnt = 0;
            rep1(j, i, i + k - 1) {
                if (s[j] != m[curr]) cnt++;
                curr = m[curr];
            }
            ans = min(ans, cnt);
        }
        printf("%d\n", ans);
    }
    return 0;
}