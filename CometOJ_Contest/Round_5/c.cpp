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
vector<int>adj[maxn], b[maxn];
multiset<int>lim;
priority_queue<int, vector<int>, greater<int>>q;

void dfs(int x, int f) {
    depth[x] = depth[f] + 1;
    b[depth[x]].pb(x);
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
    rep1(i, 2, n) lim.insert(a[i]);
    printf("1 ");
    if (n == 1) puts("");
    int curr = 1, minn = 1;
    while (curr != n) {
        while (lim.size() && minn < *lim.begin()) {
            minn++;
            for (auto x : b[minn]) q.push(x);
        }
        int x = q.top();
        lim.erase(lim.find(a[x]));
        q.pop();
        printf("%d ", x);
        curr++;
        if (curr == n) puts("");
    }
    return 0;
}