#include <bits/stdc++.h>
using namespace std;

struct island {
    int num[100010], n, deg[100010], vis[100010];
    vector<int> v[100010];
    int solve() {
        scanf("%d", &n);
        for (int i = 1, x, y; i < n; i++) {
            scanf("%d%d", &x, &y);
            v[x].push_back(y), v[y].push_back(x);
            deg[x]++, deg[y]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
            if (deg[i] == 1)
                q.push(i), vis[i]++;
        int cur = 0;
        while (!q.empty()) {
            int num_q = q.size();
            while (num_q--) {
                int x = q.front();
                q.pop();
                num[cur]++;
                for (auto i : v[x])
                    if (!vis[i]) {
                        vis[i]++, q.push(i);
                    }
            }
            cur++;
        }
        return cur - 1;
    }
} l, r;

int main() {
    int maxx = max(l.solve(), r.solve());
    long long ans = 0;
    int suml = l.n - l.num[0], sumr = r.n - r.num[0];

    for (int i = 1; i <= maxx; i++) {
        ans += 1ll * suml * sumr;
        suml -= l.num[i], sumr -= r.num[i];

        //printf("%.12lf\n", ans);
    }
    printf("%.12lf\n", 1.0 * ans / l.n / r.n);
}