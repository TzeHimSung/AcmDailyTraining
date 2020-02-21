#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 10;
vector<int>e[maxn];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n * (n - 1) / 2; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[u].push_back(w);
        e[v].push_back(w);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        sort(e[i].begin(), e[i].end());
        for (int j = 0; j < e[i].size(); j += 2) ans += max(e[i][j], e[i][j + 1]);
    }
    tuple<int, int, int>t;
    t.
    printf("%lld\n", ans);
}