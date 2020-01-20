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

int t, n, s, k;
set<int>a;

int main() {
    scanf("%d", &t);
    while (t--) {
        a.clear();
        scanf("%d%d%d", &n, &s, &k);
        for (int i = 1; i <= k; i++) {
            int x; scanf("%d", &x);
            a.insert(x);
        }
        int ans = 0;
        while (1) {
            if (s + ans <= n && !a.count(s + ans)) break;
            if (s - ans > 0 && !a.count(s - ans)) break;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}