#include<bits/stdc++.h>

using namespace std;

const int N = 567890;

int n, a[N], depth[N];
vector<int> adj[N], nodes[N];
bool visit[N];

void dfs(int x, int f) {
    nodes[depth[x] = depth[f] + 1].push_back(x);
    for (auto y : adj[x]) {
        if (y != f) {
            dfs(y, x);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1, x, y; i < n; ++i) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    multiset<int> s;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 2; i <= n; ++i) {
        s.insert(a[i]);
    }
    cout << 1 << " \n"[n == 1];
    int j = 1, tt = 1;
    while (tt != n) {
        while (s.size() && j < *s.begin()) {
            ++j;
            for (auto x : nodes[j]) {
                q.push(x);
            }
        }
        int x = q.top();
        s.erase(s.find(a[x]));
        q.pop();
        cout << x << " \n"[++tt == n];
    }
    return 0;
}