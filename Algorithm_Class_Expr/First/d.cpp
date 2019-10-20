/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(_a,_b) sort(_a+1,_a+1+_b)
#define rep1(i,_a,_b) for(int i=_a;i<=_b;++i)
#define rep0(i,_a,_b) for(int i=_a;i<_b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 20;
struct Point {
    int x, y;
    Point() {}
    Point(int _x, int _y): x(_x), y(_y) {}
    bool operator<(const Point &rhs)const {
        return y < rhs.y;
    }
};
Point p[maxn], tmp[maxn], stack1[maxn], stack2[maxn]; //signal stack
ll ans = 0;

void cdq_divition(int l, int r) {
    if (l == r) return;
    int mid = l + r >> 1;
    cdq_divition(l, mid); cdq_divition(mid + 1, r);
    int now = l, stTop1 = 0, stTop2 = 0;
    for (int i = mid + 1; i <= r; i++) {
        int currX = p[i].x, currY = p[i].y;
        while (stTop1 && stack1[stTop1].y >= currY) stTop1--;
        stack1[++stTop1] = p[i];
        while (now <= mid && p[now].x < currX) {
            int yy = p[now].y;
            while (stTop2 && stack2[stTop2].y <= yy) stTop2--;
            stack2[++stTop2] = p[now++];
        }
        int k = stack1[stTop1 - 1].x, remain = stTop2 + 1;
        // 二分
        int L = 1, R = stTop2;
        while (L <= R) {
            int MID = L + R >> 1;
            if (stack2[MID].x >= k) remain = MID, R = MID - 1;
            else L = MID + 1;
        }
        ans += stTop2 - remain + 1;
    }
    int _a = l, _b = mid + 1;
    for (int i = l; i <= r; i++) {
        if (_b > r || (p[_a].x < p[_b].x && _a <= mid)) tmp[i] = p[_a++];
        else tmp[i] = p[_b++];
    }
    for (int i = l; i <= r; i++) p[i] = tmp[i];
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        p[i] = Point(x, y);
    }
    sort(p + 1, p + 1 + n);
    stack1[0].x = stack2[0].x = -1;
    cdq_divition(1, n);
    printf("%lld\n", ans);
    return 0;
}
