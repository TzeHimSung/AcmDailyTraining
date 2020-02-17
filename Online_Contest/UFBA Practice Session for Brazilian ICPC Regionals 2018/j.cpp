/*
先具体讲一下这题的解法，再分析一下复杂度。用并查集维护图中的连通关系，对于当前节点，最后求其重儿子子树所形成的并查集，
并将重儿子的并查集直接复用在求父节点上。对于非重儿子节点再对其子树中的边进行添加。

非常暴力的做法…但是为什么能够快速通过呢…我们先考虑一下序列上的启发式合并，由于每次选择将小的合并进大的，
所以每个元素的大小每次至少∗2*2∗2，因此最多被合并logloglog次就可以达到nnn的大小，所以复杂度是nlognnlognnlogn。

而对于树上的启发式合并，每次将小的子树合并进大的子树中，因此子树的大小每次至少∗2*2∗2，
因此最多lognlognlogn次子树的大小就可以达到nnn，因此复杂度也是nlognnlognnlogn。
 */

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