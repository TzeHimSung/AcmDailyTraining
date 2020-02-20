#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

vector<int> g[400010];
vector<int> v;
int a[400010], deg[400010];
int main() {
    v.push_back(0);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int j;
        scanf("%d%d", &a[i], &j);
        while (j--) {
            int x;
            scanf("%d", &x);
            g[i].push_back(x - 1);
            deg[x - 1]++;
        }
    }
    int ans = 0;
    priority_queue<pii> pq;
    for (int i = 0; i < n; i++)
        if (!deg[i]) pq.push(mp(-a[i], i));
    while (!pq.empty()) {
        pii x = pq.top();
        pq.pop();
        v.push_back(-x.ff);
        for (auto i : g[x.ss]) {
            deg[i]--;
            if (!deg[i])
                pq.push(mp(-a[i], i));
        }
    }
    reverse(v.begin(), v.end());
    for (int i = 0; i < n; i++) ans = max(ans, v[i] + i);
    printf("%d\n", ans);
}