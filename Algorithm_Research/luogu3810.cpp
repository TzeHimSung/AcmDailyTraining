/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
struct Node {
    int a, b, c;
    Node() {}
    Node(int _a, int _b, int _c): a(_a), b(_b), c(_c) {}

    bool operator<(const Node &rhs)const {
        return a != rhs.a ? a < rhs.a : b != rhs.b ? b < rhs.b : c < rhs.c;
    }
};
Node a[maxn];
int n, k, ans[maxn << 1];

bool cmpy(const Node &lhs, const Node &rhs) {
    return lhs.b != rhs.b ? lhs.b < rhs.b : lhs.c < rhs.c;
}

void cdq_divition(int curl, int curr) {
    if (curl == curr) return;
    int mid = curl + curr >> 1;
    cdq_divition(curl, mid); cdq_divition(mid + 1, curr);
	sort(a+curl,a+mid+1,cmpy); sort(a+mid+1,a+curr+1,cmpy);

}

int main() {
    // init
    scanf("%d%d", &n, &k);
    for (int i = 0; i <= k; i++) ans[i] = 0;
    for (int i = 1; i <= n; i++) {
        int x, y, z; scanf("%d%d%d", &x, &y, &z);
        a[i] = Node(x, y, z);
    }
    // 1d
    sort(a + 1, a + 1 + n);
    // 2d
    cdq_divition(1, n);

    // output
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}

