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

int n;
vector<pair<int, int>>v;
double ans = 0;

int main() {
    freopen("input", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        v.pb(mp(x, y));
        ans = max(ans, double(x) * double(y) / 2.0);
    }
    for (int i = 0; i < (int)v.size(); i++) {
        for (int j = i + 1; j < (int)v.size(); j++) {
            ans = max(ans, (double)min(v[i].first, v[j].first) * (double)min(v[i].second, v[j].second));
            ans = max(ans, (double)min(v[i].first, v[j].second) * (double)min(v[i].second, v[j].first));
        }
    }
    printf("%.1f\n", ans);
    fclose(stdin);
    return 0;
}