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

const int maxn = 1e5 + 10;
map<pair<ll, ll>, int>m;
pair<ll, ll>a[maxn];
int n;
ll midX = 0, midY = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i].first, &a[i].second);
        // 放缩坐标，防止出现小数
        a[i].first *= n, a[i].second *= n;
        midX += a[i].first, midY += a[i].second;
        m[mp(a[i].first, a[i].second)] = 1;
    }
    midX /= n, midY /= n;
    for (int i = 1; i <= n; i++) {
        if (!m.count(mp(2 * midX - a[i].first, 2 * midY - a[i].second))) {
            return puts("NO"), 0;
        }
    }
    puts("YES");
    return 0;
}