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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 5e5 + 10;
int n, a[maxn], depth[maxn], vis[maxn];
vector<int>adj[maxn], nodes[maxn];
multiset<int>s;
priority_queue<int, vector<int>, greater<int>>q;

void dfs(int x, int f) {
    node[depth[x] = depth[f] + 1].pb(x);
    for (auto i : adj[x])
        if (i != f) dfs(i, x);
}

int main() {
    scanf("%d", &n);
    rep0(i, 1, n) {
        int x, y; scanf("%d%d", &x, &y);
        adj[x].pb(y); adj[y].pb(x);
    }
    dfs(1, 0);
    rep1(i, 1, n) scanf("%d", &a[i]);
    rep1(i, 2, n) s.insert(a[i]);
    printf("1");
    if (n == 1) puts(" ");

    return 0;
}