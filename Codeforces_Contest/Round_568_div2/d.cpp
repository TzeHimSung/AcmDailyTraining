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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
struct Node {
    Node() {}
    int val, posi;
    bool operator<(const Node &rhs)const {
        return val < rhs.val;
    }
} a[maxn];
int n;
vector<Node>b;

int main() {
    scanf("%d", &n);
    rep1(i, 1, n) {
        scanf("%d", &a[i].val);
        a[i].posi = i;
    }
    if (n == 2) return puts("1"), 0;
    sot(a, n);
    int s = a[n].val - a[1].val, pos = 1, d = s / (n - 2), cnt = 0;
    rep1(i, 1, n)
    if (a[i].val != a[1].val + d * (i - cnt - 1)) {
        pos = a[i].posi;
        cnt++;
    }
    if (cnt == 1) return printf("%d\n", pos), 0;
    s = a[n - 1].val - a[1].val; d = s / (n - 2);
    int flag = 0;
    rep1(i, 1, n - 1)
    if (a[i].val != a[1].val + d * (i - 1))
        flag = 1;
    if (!flag) return printf("%d\n", a[n].posi), 0;
    flag = 0; s = a[n].val - a[2].val; d = s / (n - 2);
    rep1(i, 2, n)
    if (a[i].val != a[2].val + d * (i - 2))
        flag = 1;
    if (!flag) return printf("%d\n", a[1].posi), 0;
    puts("-1");
    return 0;
}