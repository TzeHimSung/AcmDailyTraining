#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> point;
vector<point> pts;
bool check(point a, point b) {
    return (a.first < b.first && abs(a.first - b.first) + abs(a.second - b.second) <= 5);
}
vector<int> edges[200001];
int dp[200001];
bool vis[200001];
bool reach0[200001];
map<int, map<int, int>> Map;
void dfs(int u) {
    vis[u] = true;
    dp[u] = 1;
    for (auto v : edges[u]) {
        if (!vis[v]) dfs(v);
        if (reach0[v]) dp[u] = max(dp[u], dp[v] + 1);
        reach0[u] |= reach0[v];
    }
}
int main() {
    int n, l;
    scanf("%d%d", &n, &l);
    pts.push_back(point(0, 0));
    Map[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        pts.push_back(point(x, y));
        Map[x][y] = i + 1;
    }
    for (int i = 0; i <= n; ++i) {
        int x = pts[i].first;
        int y = pts[i].second;
        for (int j = 1; j <= 5; ++j) {
            if (Map.find(x + j) == Map.end()) continue;
            auto iter = Map[x + j].lower_bound(y - (5 - j));
            while (iter != Map[x + j].end() && iter->first <= y + 5 - j) {
                edges[iter->second].push_back(i);
                iter++;
            }
        }
    }
    reach0[0] = true;
    for (int i = 0; i <= n; ++i)
        if (!vis[i]) dfs(i);
    point end = {l, 0};
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        if (reach0[i] && check(pts[i], end)) ans = max(ans, dp[i] - 1);
    }
    printf("%d", ans);
}