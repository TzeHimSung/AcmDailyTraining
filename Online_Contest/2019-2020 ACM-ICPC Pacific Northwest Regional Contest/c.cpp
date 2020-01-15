#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define ff first
#define ss second
#define mp make_pair

vector<int>v[100010];
int vis[100010];
int main() {
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    queue<pii>q;
    q.push(mp(0, 1));
    while (!q.empty()) {
        pii x = q.front(); q.pop();
        if (vis[x.ss])continue;
        vis[x.ss]++;
        for (auto i : v[x.ss])
            if (!vis[i]) {
                if (i == n) {
                    printf("%d\n", x.ff); return 0;
                }
                q.push(mp(x.ff + 1, i));
            }
    }
}