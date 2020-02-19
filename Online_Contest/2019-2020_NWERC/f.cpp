#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

int f[200010];
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
bool add(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx != fy) {
        f[fx] = fy;
        return true;
    }
    return false;
}
int main() {
    int n;
    scanf("%d", &n);
    map<int, vector<int>> m;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        int j, k;
        scanf("%d", &j);
        while (j--) {
            scanf("%d", &k);
            m[k].push_back(i);
        }
    }
    vector<pair<pii, int>> ans;
    for (auto i : m) {
        for (int j = 1; j < i.ss.size(); j++)
            if (add(i.ss[j - 1], i.ss[j]))
                ans.push_back({ { i.ss[j - 1], i.ss[j] }, i.ff });
    }
    if (ans.size() != n - 1)
        printf("impossible\n");
    else
        for (auto i : ans)
            printf("%d %d %d\n", i.ff.ff, i.ff.ss, i.ss);
}