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

const double pi = acos(-1.0);

struct Point {
    double x, y, len;
};

double distant(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double getAngle(Point a, Point b) {
    return acos((a.x * b.x + a.y * b.y) / (a.len * b.len));
}

int main() {
    int t; scanf("%d", &t);
    for (int __ = 1; __ <= t; __++) {
        int n; scanf("%d", &n);
        vector<Point> a(n), v(n);
        for (auto &i : a) scanf("%lf%lf", &i.x, &i.y);
        for (int i = 0; i < n - 1; i++) {
            v[i].x = a[i + 1].x - a[i].x;
            v[i].y = a[i + 1].y - a[i].y;
            v[i].len = distant(a[i + 1], a[i]);
        }
        v[n - 1].x = a[0].x - a[n - 1].x;
        v[n - 1].y = a[0].y - a[n - 1].y;
        v[n - 1].len = distant(a[0], a[n - 1]);
        Point g; scanf("%lf%lf", &g.x, &g.y);
        double ans = 0.0, r = distant(g, a[0]);
        ans += abs(getAngle(v[n - 1], v[0]) * r);
        for (int i = 0; i < n - 1; i++) {
            double r = distant(g, a[i + 1]);
            ans += abs(getAngle(v[i], v[i + 1]) * r);
        }
        printf("Case #%d: %.3f\n", __, ans);
    }
    return 0;
}

