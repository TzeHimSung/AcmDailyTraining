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

const int maxn = 2e5 + 10;
int root[maxn], cnt = 0;
ll preLen = 0;

struct Node {
    ll sum;
    int num, l, r; // 主席树维护区间元素个数，区间和
} segt[maxn * 40];

void insert(int pos, int &cr, int lr, int curl, int curr) {
    cr = ++cnt; segt[cr].num = segt[lr].num + 1; segt[cr].sum = segt[lr].sum + pos;
    if (curl == curr) return;
    int mid = curl + curr >> 1;
    segt[cr].l = segt[lr].l, segt[cr].r = segt[lr].r;
    if (pos <= mid) insert(pos, segt[cr].l, segt[lr].l, curl, mid);
    else insert(pos, segt[cr].r, segt[lr].r, mid + 1, curr);
}

double query(int cr, int lr, int curl, int curr, double k, int remainNum) {
    if (curl == curr) return (k - preLen) / remainNum;
    int mid = curl + curr >> 1, currNum = segt[segt[lr].l].num - segt[segt[cr].l].num;
    ll sum = preLen + segt[segt[lr].l].sum - segt[segt[cr].l].sum + (ll)mid * (remainNum - currNum);
    if (sum - k < eps) {
        preLen += segt[segt[lr].l].sum - segt[segt[cr].l].sum;
        return query(segt[cr].r, segt[lr].r, mid + 1, curr, k, remainNum - currNum);
    } else
        return query(segt[cr].l, segt[lr].l, curl, mid, k, remainNum);
}

int main() {
    int n, q; scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        insert(x, root[i], root[i - 1], 1, 1e5);
    }
    while (q--) {
        int l, r, x, y; scanf("%d%d%d%d", &l, &r, &x, &y);
        ll totalLen = segt[root[r]].sum - segt[root[l - 1]].sum;
        double perCutLen = (double)totalLen / y;
        double remainLen = totalLen - perCutLen * x;
        if (fabs(remainLen < eps)) remainLen = 0;
        preLen = 0;
        printf("%.10f\n", query(root[l - 1], root[r], 1, 1e5, remainLen, r - l + 1));
    }
    return 0;
}