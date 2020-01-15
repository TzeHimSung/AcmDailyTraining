#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

ll dp1[100010], dp2[100010], ans[100010];
int t[100010], sz[100010], sumt[100010], n, T;
vector<pii> v[100010];
void dfs0(int x, int pre) {
    for (auto i : v[x])
        if (i.ff != pre) {
            dfs0(i.ff, x);
            sz[x] += sz[i.ff];
            sumt[x] += sumt[i.ff];
            dp1[x] += 1ll * sz[i.ff] * i.ss + dp1[i.ff];
            dp2[x] += 1ll * sumt[i.ff] * i.ss + dp2[i.ff];
        }
    sumt[x] += t[x];
    sz[x]++;
}
void dfs(int x, int pre) {
    ans[x] = 1ll * t[x] * dp1[x] + dp2[x];
    for (auto i : v[x])
        if (i.ff != pre) {
            dp1[i.ff] = dp1[x] + 1ll * i.ss * (n - sz[i.ff]) - 1ll * sz[i.ff] * i.ss;
            dp2[i.ff] = dp2[x] + 1ll * (T - sumt[i.ff]) * i.ss - 1ll * sumt[i.ff] * i.ss;
            dfs(i.ff, x);
        }
}
int main() {
    scanf("%d", &n);
    T = 0;
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]), T += t[i];
    for (int i = 1; i <= n - 1; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        v[x].push_back(mp(y, z));
        v[y].push_back(mp(x, z));
    }
    dfs0(1, -1);
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
        printf("%lld\n", ans[i]);
}