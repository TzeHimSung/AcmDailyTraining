#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v[200010];
int mark[200010], ismark[200010];
int st[200010], num = 0, ans = 0, ansn;
int dep[200010];
void dfs1(int x, int pre, int d) {
    st[++num] = x;
    if (ismark[x] && ans < d)ans = d, ansn = st[num + 1 >> 1];
    for (auto i : v[x])
        if (i != pre)
            dfs1(i, x, d + 1);
    num--;
}
void dfs2(int x, int pre, int d) {
    dep[x] = d;
    for (auto i : v[x])
        if (i != pre)
            dfs2(i, x, d + 1);
}
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= m; i++)scanf("%d", &mark[i]), ismark[mark[i]]++;
    if (m == 1) {
        printf("YES\n1\n");
        return 0;
    }
    dfs1(mark[1], -1, 0);
    if (ans & 1) {
        printf("NO\n"); return 0;
    }
    dfs2(ansn, -1, 1);
    for (int i = 2; i <= m; i++)
        if (dep[mark[i - 1]] != dep[mark[i]]) {
            printf("NO\n");
            return 0;
        }
    printf("YES\n%d\n", ansn);
}