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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int n, sum[maxn << 2], minn[maxn << 2], lp;

//维护
void maintain(int curpos) {
    sum[curpos] = sum[lson] + sum[rson];
    minn[curpos] = min(minn[lson] + minn[rson]);
}

//非递归建树，注意这里是倒着建的，时间复杂度O(n)
void build() {
    for (lp = 1; lp < n; lp <<= 1);
    for (int i = lp + 1; i <= lp + n; i++) scanf("%d", &sum[i]);
    for (int i = lp - 1; i; i--) maintain(i);
}

//单点修改
void update(int pos, int val) {
    pos += lp; //确定叶子位置只需O(1)
    sum[pos] = val;
    for (pos >>= 1; pos; pos >>= 1) maintain(pos);
    //还有一种压行写法
    // sum[pos += lp] = val;
    // while (pos) maintain(sum[pos >>= 1]);
}

//区间和查询
int querySum(int l, int r) {
    int ret = 0;
    //这里较难理解，l^r^1==0时其实就是区间相交的边界。
    for (l += lp - 1, r += lp + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
        if (~l & 1) ret += minn[l ^ 1];
        if (r & 1) ret += minn[r ^ 1];
    }
    return ret;
}

//有bug
int queryMin(int l, int r) {
    int L = 0, R = 0;
    for (l += lp - 1, r += lp + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
        L += sum[l], R += sum[r];
        if (~l & 1) L = min(L, sum[l ^ 1]);
        if (r & 1) R = min(R, sum[r ^ 1]);
    }
    int ret = min(L, R); while (l) ret += sum[l >>= 1];
}

int main() {
    scanf("%d", &n);
    build();
    int q; scanf("%d", &q);
    while (q--) {
        int op; scanf("%d", &op);
        if (op == 1) {
            int pos, val; scanf("%d%d", &pos, &val);
            update(pos, val);
        } else if (op == 2) {
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", querySum(l, r));
        } else if (op == 3) {
            int l, r; scanf("%d%d", &l, &r);
            printf("%d\n", queryMin(l, r));
        }
    }
    return 0;
}
