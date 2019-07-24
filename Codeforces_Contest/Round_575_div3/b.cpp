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

const int maxn = 2e5 + 10;
// const int maxn = 10;
int q, a[maxn];
vector<int>ans;

int main() {
    scanf("%d", &q);
    while (q--) {
        int n, k;
        ans.clear();
        scanf("%d%d", &n, &k);
        rep1(i, 1, n) {
            int x; scanf("%d", &x);
            if (x & 1) a[i] = 1; else a[i] = 0;
            a[i] += a[i - 1];
        }
        int re = k, flag = 1, lastPos = 0;
        rep1(i, 1, n) {
            if (re == 1)
                if ((a[n] - a[i - 1]) % 2) {
                    re--; ans.pb(n); break;
                } else {
                    flag = 0; break;
                }
            if ((a[i] - a[lastPos]) % 2) {
                re--;
                ans.pb(i);
                lastPos = i;
            }
        }
        if (flag && !re) {
            // have solution
            puts("YES");
            for (auto i : ans) printf("%d ", i);
            puts("");
        } else puts("NO");
    }
    return 0;
}