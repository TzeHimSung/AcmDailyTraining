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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 5e5 + 10;
int n, top = 0, maxx, pos, cur;
ll ans = 0;
int head[maxn], nxt[maxn], edge[maxn], depth[maxn], size[maxn];

void addEdge(int x, int y) {
    edge[++top] = y;
    nxt[top] = head[x];
    head[x] = top;
}

void dfs(int x, int fa) {
    size[x] = 1;
    for (int i = head[x]; i; i = nxt[i]) {
        int v = edge[i];
        if (v == fa) continue;
        depth[v] = depth[x] + 1;
        dfs(v, x);
        size[x] += size[v];
    }
}

void calc(int x, int fa, ll num) {
    ans = max(ans, num);
    for (int i = head[x]; i; i = nxt[i]) {
        int v = edge[i];
        if (v == fa) continue;
        calc(v, x, num + n - 2 * size[v]);
    }
}

int main() {
    scanf("%d", &n);
    rep0(i, 1, n) {
        int x, y; scanf("%d%d", &x, &y);
        addEdge(x, y); addEdge(y, x);
    }
    depth[1] = 1;
    dfs(1, 0);
    ll num = 0;
    rep1(i, 1, n) num += depth[i];
    calc(1, 0, num);
    printf("%lld\n", ans);
    return 0;
}