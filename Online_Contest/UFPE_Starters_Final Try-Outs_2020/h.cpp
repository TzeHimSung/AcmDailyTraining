#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
#define ff first
#define ss second
#define mp make_pair

const int N = 1e5 + 10;
vector<pii> v[N];
int T[N], vis[N];
ll ans[N];
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        v[x].push_back(mp(y, z));
        v[y].push_back(mp(x, z));
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &T[i]);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i <= k; i++) {
        int x;
        scanf("%d", &x);
        pq.push(mp(T[x], x));
    }

    while (!pq.empty()) {
        pii x = pq.top();
        pq.pop();
        if (vis[x.ss])
            continue;
        vis[x.ss]++;
        ans[x.ss] = x.ff;

        for (auto i : v[x.ss])
            if (!vis[i.ff])
                pq.push(mp(x.ff + i.ss + T[i.ff], i.ff));
    }
    for (int i = 1; i <= n; i++)
        printf("%lld\n", ans[i]);
}