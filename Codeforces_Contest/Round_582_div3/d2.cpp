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
int n, k, ans = int_inf;
vector<int>v[maxn];

int main() {
    scanf("%d%d", &n, &k);
    rep1(i, 1, n) {
        int x, cnt = 0; scanf("%d", &x);
        do {
            v[x].pb(cnt);
            x >>= 1;
            cnt++;
        } while (x);
    }
    for (int i = 0; i < maxn; i++) {
        if ((int)v[i].size() < k) continue;
        sort(v[i].begin(), v[i].end());
        int tot = 0;
        for (int j = 0; j < k; j++) tot += v[i][j];
        ans = min(ans, tot);
    }
    printf("%d\n", ans);
    return 0;
}
