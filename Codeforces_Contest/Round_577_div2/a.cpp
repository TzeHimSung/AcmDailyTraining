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

int n, m;
string s[1010];
int a[1010];
ll ans = 0;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= m; i++) cin >> a[i];
    for (int j = 0; j < m; j++) {
        int maxx = 0; map<char, int>m;
        for (int i = 1; i <= n; i++) maxx = max(maxx, ++m[s[i][j]]);
        ans += (ll)maxx * a[j + 1];
    }
    printf("%lld\n", ans);
    return 0;
}