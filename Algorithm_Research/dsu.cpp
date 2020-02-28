// luogu p3367
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

const int maxn = 1e4 + 10;
int n, m, fa[maxn], _rank[maxn]; // 有按秩合并

int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) fa[i] = i, _rank[i] = 0;
    while (m--) {
        int op, x, y; scanf("%d%d%d", &op, &x, &y);
        int f1 = find(x), f2 = find(y);
        if (op == 2) {
            printf("%c\n", f1 == f2 ? 'Y' : 'N');
        } else {
            if (_rank[f1] > _rank[f2]) fa[f2] = f1;
            else {
                fa[f1] = f2;
                if (_rank[f1] == _rank[f2]) _rank[f2]++;
            }
        }
    }
    return 0;
}