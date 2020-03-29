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

const int MAXN = 17;
pair<int, int>point[MAXN];
int n, ans = 0, vis[MAXN];
map<pair<int, int>, int>m;

int main() {
    memset(vis, 0, sizeof(vis));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &point[i].first, &point[i].second);

    function<void(int, int, int)> dfs = [&](int cnt, int tot, int sum) {
        if (tot == n / 2 + 1) {
            ans = max(sum, ans);
            return;
        }
        if (vis[cnt]) dfs(cnt + 1, tot, sum);
        else {
            vis[cnt] = 1;
            for (int i = cnt + 1; i <= n; i++) {
                if (vis[i]) continue;
                int curX = point[cnt].first - point[i].first, curY = point[cnt].second - point[i].second;
                if (!curX) curY = 1001;
                else if (!curY) curX = 1001;
                else {
                    int gcd = __gcd(abs(curX), abs(curY));
                    curX /= gcd, curY /= gcd;
                    if (curX < 0 && curY < 0) curX = -curX, curY = -curY;
                }
                m[mp(curX, curY)]++;
                vis[i] = 1;
                dfs(cnt + 1, tot + 1, sum + m[mp(curX, curY)] - 1);
                m[mp(curX, curY)]--;
                vis[i] = 0;
            }
            vis[cnt] = 0;
        }
    };

    dfs(1, 1, 0);
    printf("%d\n", ans);
    return 0;
}