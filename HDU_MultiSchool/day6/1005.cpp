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
} segt[maxn * 4];

void maintain(int curpos) {
    segt[curpos].sum = segt[lson].sum + segt[rson].sum;
    segt[curpos].maxv = max(segt[lson].maxv, segt[rson].maxv);
    segt[curpos].maxv = max(segt[curpos].maxv, segt[lson].sufv + segt[rson].prev);
    segt[curpos].prev = max(segt[lson].prev, segt[lson].sum + segt[rson].prev);
    segt[curpos].sufv = max(segt[lson].sufv + segt[lson].sum, segt[rson].sufv);
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

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        vector<int>keyX, keyY;
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].c);
            keyX.pb(p[i].x); keyY.pb(p[i].y);
        }
        sort(keyX.begin(), keyX.end());
        sort(keyY.begin(), keyY.end());
        int pp = unique(keyX.begin(), keyX.end()) - keyX.begin();
        int qq = unique(keyY.begin(), keyY.end()) - keyY.begin();
        for (int i = 0; i < n; i++) {
            p[i].x = lower_bound(keyX.begin(), keyX.begin() + pp, p[i].x) - keyX.begin() + 1;
            p[i].y = lower_bound(keyY.begin(), keyY.begin() + qq, p[i].y) - keyY.begin() + 1;
        }
        sort(p, p + n);

    }
    return 0;
}