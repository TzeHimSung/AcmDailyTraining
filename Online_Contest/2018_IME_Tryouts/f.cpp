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

const int MAXN = 1e5 + 10;
pair<int, int>edge[MAXN];
int n, m, cnt, fa[MAXN], p[MAXN], ans[MAXN];

int main() {
    scanf("%d%d", &n, &m); cnt = n;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d%d", &u, &v);
        edge[i] = mp(u, v);
    }

    function<int(int)>findFa = [&](int cur)->int{
        return fa[cur] == cur ? cur : fa[cur] = findFa(fa[cur]);
    };

    for (int i = 1; i <= m; i++) scanf("%d", &p[i]);
    for (int i = m; i >= 1; i--) {
        ans[i] = cnt;
        int fa1 = findFa(edge[p[i]].first), fa2 = findFa(edge[p[i]].second);
        if (fa1 != fa2) {
            fa[fa1] = fa2;
            cnt--;
        }
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
    return 0;
}