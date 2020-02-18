/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define pb emplace_back
#define mp make_pair
#define eps 1e-8
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y): x(_x), y(_y) {}
};

double solve(const vector<Point> &p) {
    double area = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        int j = (i + 1) % (int)p.size();
        area += p[i].x * p[j].y - p[j].x * p[i].y;
    }
    return fabs(area / 2.0);
}

int n;
double ans = 0;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int t; scanf("%d", &t);
        vector<Point>v;
        while (t--) {
            double x, y; scanf("%lf%lf", &x, &y);
            v.pb(Point(x, y));
        }
        ans += solve(v);
    }
    printf("%.f\n", floor(ans));
    return 0;
}