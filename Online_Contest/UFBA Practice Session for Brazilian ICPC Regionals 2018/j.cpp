/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
struct Street {
    int l, r;
} str[maxn];
int n, k, ans[maxn];
vector<int>boss[maxn];

/* 树上启发式合并 (CF 741D)----------------------------------------------------------- */
// 以下内容全抄
int fa[maxn], _size[maxn], remain;

void init() {
    for (int i = 0; i < maxn; i++) _size[i] = 1, fa[i] = i;
}

int findFa(int x) {
    return x == fa[x] ? x : (fa[x] = findFa(fa[x]));
}

void cleanInfo(int x) {
    fa[str[x].l] = str[x].l, fa[str[x].r] = str[x].r;
    for (int i : boss[x]) cleanInfo(i);
}

void merge(int x, int y) {
    int fx = findFa(x), fy = findFa(y);
    if (fx != fy) fa[fx] = fy, remain--;
}

void solve(int x) {
    merge(str[x].l, str[x].r);
    for (auto i : boss[x]) solve(i);
}

void dfs(int x) {
    int heavySon = -1;
    // 从最小的size开始处理
    for (auto i : boss[x]) if (_size[heavySon] < _size[i] || heavySon == -1) heavySon = i;
    for (auto i : boss[x]) {
        if (i == heavySon) continue;
        remain = k;
        dfs(i), cleanInfo(i); // dfs后不要忘记清除信息！
    }
    remain = k;
    if (heavySon != -1) dfs(heavySon);
    for (auto i : boss[x]) if (i != heavySon) solve(i);
    merge(str[x].l, str[x].r);
    ans[x] = remain;
}

/* ----------------------------------------------------------------------------------- */

int main() {
    init();
    scanf("%d%d", &n, &k);
    for (int i = 2; i <= n; i++) {
        int x; scanf("%d", &x);
        boss[x].pb(i);
    }
    for (int i = 1; i <= n; i++) scanf("%d%d", &str[i].l, &str[i].r);
    for (int i = n; i >= 1; i--) {
        for (auto j : boss[i]) _size[i] += _size[j];
    }
    dfs(1);
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}