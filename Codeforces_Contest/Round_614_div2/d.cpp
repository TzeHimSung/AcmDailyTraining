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

ll xZero, yZero, ax, ay, bx, by, sx, sy, t;

ll getDis(ll x0, ll y0, ll x1, ll y1) {
    return abs(x0 - x1) + abs(y0 - y1);
}

int main() {
    scanf("%lld%lld%lld%lld%lld%lld", &xZero, &yZero, &ax, &ay, &bx, &by);
    scanf("%lld%lld%lld", &sx, &sy, &t);
    ll xi = xZero, yi = yZero, xj, yj, xp = xZero, yp = yZero, i = 0, j = 0, p = 0, ans = 0;
    ll currDis = getDis(xi, yi, sx, sy), lastDis = currDis + 1;
    while (currDis > t && lastDis > currDis) {
        xi = xi * ax + bx, yi = yi * ay + by, i++, lastDis = currDis;
        // calculate distance of each point to start point
        currDis = getDis(xi, yi, sx, sy);
        while (currDis + getDis(xi, yi, xp, yp) > t && p <= i) {
            xp = xp * ax + bx, yp = yp * ay + by, p++;
        }
    }
    j = i; xj = xi; yj = yi;
    while (currDis <= t) {
        while (currDis + getDis(xi, yi, xj, yj) <= t) {
            xj = xj * ax + bx, yj = yj * ay + by, j++;
        }
        ans = max(ans, j - i);
        while (currDis + getDis(xi, yi, xp, yp) > t) {
            xp = xp * ax + bx, yp = yp * ay + by, p++;
        }
        ans = max(ans, i - p + 1);
        xi = xi * ax + bx, yi = yi * ay + by, i++;
        currDis = getDis(xi, yi, sx, sy);
    }
    printf("%lld\n", ans);
    return 0;
}