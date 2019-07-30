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

const int maxn = 4e5 + 10;
int n, m, a[maxn], k = 0, ans = int_inf, sum[maxn];
ll K;

int main() {
    scanf("%d%d", &n, &m); k = m * 8 / n;
    if (k > 33) k = 33;
    K = pow(2, k);
    rep1(i, 1, n) scanf("%d", &a[i]);
    sot(a, n);
    vector<pair<int, int>>v; // num,times
    int cnt = 1;
    rep1(i, 2, n) {
        if (a[i] == a[i - 1]) cnt++;
        else {
            v.pb(mp(a[i - 1], cnt));
            cnt = 1;
        }
    }
    v.pb(mp(a[n], cnt));
    int vsize = v.size();
    sum[0] = 0;
    for (int i = 0; i < vsize; i++)
        sum[i + 1] = sum[i] + v[i].second;
    rep1(i, 1, n - K + 1) {
        ans = min(ans, n - (sum[i + K - 1] - sum[i - 1]));
    }
    printf("%d\n", ans);
    return 0;
}