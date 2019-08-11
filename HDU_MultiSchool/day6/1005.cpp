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

const int maxn = 2e3 + 10;
struct Point {
    int x, y, c;
    bool operator<(const Point &rhs)const {
        return x < rhs.x || (x == rhs.x && y < rhs.y);
    }
} p[maxn];

struct Node {
    ll sum, maxv, prev, sufv;
} segt[maxn << 2];

void maintain(int curpos) {
    segt[curpos].sum = segt[lson].sum + segt[rson].sum; // 总和
    segt[curpos].maxv = max(segt[lson].maxv, segt[rson].maxv); // 答案
    segt[curpos].maxv = max(segt[curpos].maxv, segt[lson].sufv + segt[rson].prev); //不拿当前的点
    segt[curpos].prev = max(segt[lson].prev, segt[lson].sum + segt[rson].prev); // 最大前缀和
    segt[curpos].sufv = max(segt[lson].sufv + segt[rson].sum, segt[rson].sufv); // 最大后缀和
}

void build(int curpos, int curl, int curr) {
    if (curl == curr) {
        segt[curpos].maxv = segt[curpos].prev = segt[curpos].sufv = segt[curpos].sum = 0;
        return;
    }
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
    maintain(curpos);
}

void update(int pos, int curpos, int curl, int curr, ll v) {
    if (curl == curr) {
        segt[curpos].sum += v;
        segt[curpos].maxv = segt[curpos].prev = segt[curpos].sufv = max(0ll, segt[curpos].sum); // 不拿就是0
        return;
    }
    int mid = curl + curr >> 1;
    if (pos <= mid) update(pos, lson, curl, mid, v);
    else update(pos, rson, mid + 1, curr, v);
    maintain(curpos);
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        vector<int>keyX, keyY;
        int n; scanf("%d", &n); ll ans = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].c);
            keyX.pb(p[i].x); keyY.pb(p[i].y);
        }
        sort(keyX.begin(), keyX.end());
        sort(keyY.begin(), keyY.end());
        int totalX = unique(keyX.begin(), keyX.end()) - keyX.begin();
        int totalY = unique(keyY.begin(), keyY.end()) - keyY.begin();
        // 把点的xy值都离散化
        for (int i = 0; i < n; i++) {
            p[i].x = lower_bound(keyX.begin(), keyX.begin() + totalX, p[i].x) - keyX.begin() + 1;
            p[i].y = lower_bound(keyY.begin(), keyY.begin() + totalY, p[i].y) - keyY.begin() + 1;
        }
        sort(p, p + n); // 先按x然后按y排序
        // 遍历totalX条边，相当于枚举矩形左边界
        for (int i = 0; i < totalX; i++) {
            int x = i + 1, tmp = 0;
            while (tmp < n && p[tmp].x < x) tmp++; // 找到在当前点在p数组中的位置
            build(1, 1, totalY); //建立空线段树
            while (tmp < n) { //扫一遍点, 计算后面所有x相同的点
                int curx = p[tmp].x;
                while (tmp < n && p[tmp].x == curx) {
                    update(p[tmp].y, 1, 1, totalY, p[tmp].c);
                    tmp++;
                }
                ans = max(ans, segt[1].maxv);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}