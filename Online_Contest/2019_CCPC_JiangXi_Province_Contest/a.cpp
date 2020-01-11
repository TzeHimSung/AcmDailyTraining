#include <bits/stdc++.h>
using namespace std;
vector<int> li[100001];
long long pTotal[100001];
long long Size[100001];
void dfs(int x, int f, int d, int root) {
    Size[x] = 1;
    pTotal[root] += d;
    for (auto i : li[x]) {
        if (i == f) continue;
        dfs(i, x, d + 1, root);
        Size[x] += Size[i];
    }
}
long long Min = 1e18;
void calpTotal(int x, int f, int sum) {
    if (x != f) pTotal[x] = pTotal[f] + sum - 2 * Size[x];
    Min = min(Min, pTotal[x]);
    for (auto i : li[x]) {
        if (i == f) continue;
        calpTotal(i, x, sum);
    }
}
void getInnerSum(int x, int f, long long &innerSum, int sum) {
    for (auto i : li[x]) {
        if (i == f) continue;
        innerSum += Size[i] * (sum - Size[i]);
        getInnerSum(i, x, innerSum, sum);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 2; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        li[u].push_back(v);
        li[v].push_back(u);
    }
    int root1, root2;
    for (int i = 1; i <= n; ++i)
        if (!Size[i]) {
            root1 = i;
            dfs(i, i, 0, i);
            break;
        }
    for (int i = 1; i <= n; ++i)
        if (!Size[i]) {
            root2 = i;
            dfs(i, i, 0, i);
            break;
        }
    Min = 1e18;
    calpTotal(root1, root1, Size[root1]);
    long long totalA = Min;

    Min = 1e18;
    calpTotal(root2, root2, Size[root2]);
    long long totalB = Min;

    totalA *= Size[root2];
    totalB *= Size[root1];

    long long innerSum1 = 0, innerSum2 = 0;
    getInnerSum(root1, root1, innerSum1, Size[root1]);
    getInnerSum(root2, root2, innerSum2, Size[root2]);
    //cout<<root1<<' '<<root2<<endl;
    //cout<<Size[root1]*Size[root2]<<' '<<totalA<<' '<<totalB<<' '<<innerSum1<<' '<<innerSum2<<endl;
    printf("%lld\n", Size[root1]*Size[root2] + totalA + totalB + innerSum1 + innerSum2);
}