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
    int x, y, val;
    Point() {}
    Point(int a, int b, int c) {
        x = a, y = b, val = c;
    }
    bool operator<(const Point &rhs)const {
        if (x != rhs.x) return x < rhs.x;
        else return y < rhs.y;
    }
};

ll sum[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        ll ans = 0;
        int n; scanf("%d", &n);
        for (int i = 0; i <= n; i++) sum[i] = 0;
        vector<Point>p;
        map<pair<int, int>, int>m;
        rep1(i, 1, n) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            p.pb(Point(a, b, c)); m[mp(a, b)] = c;
        }
        sort(p.begin(), p.end());
        for (auto lp = p.begin(); lp != p.end(); lp++) {
            stack<int>upY, downY; ll currAns = lp->val;
            priority_queue<pair<int, int>>qUp, qDown; // y,val
            while (!qUp.empty()) qUp.pop(); while (!qDown.empty()) qDown.pop();
            upY.pb(lp->y); downY(lp->y);
            for (auto rp = next(lp); rp != p.end(); rp++) {
                // pickable
                if (rp->val > 0) {
                    if (rp->y > upY.top()) upY.push(rp->y);
                    if (rp->y < downY.top()) downY.push(rp->y);
                    currAns += rp->val;
                } else { // unpickable
                    if (rp->y > lp->y) qUp.push(mp(rp->y, rp->val));
                    else qDown.push(mp(rp->y, rp->val));
                }
            }
            ans = max(ans, currAns);
        }
        printf("%lld\n", ans);
    }
    return 0;
}