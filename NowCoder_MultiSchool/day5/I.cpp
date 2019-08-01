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
#define eps 1e-10
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

#define Point pair<double, double>
const double pi = acos(-1.0);
int w, h;

int solve(int a, int b, int c, Point &x, Point &y) {
    double alpha = 0;
    if (a <= h) x.first = 0, x.second = (double)a;
    else {
        x.first = sqrt((double)a * a - (double)h * h), x.second = (double)h;
        alpha = acos((double)h / (double)a);
    }
    double beta = acos((double)(a * a + b * b - c * c ) / (2.0 * a * b));
    double gamma = pi / 2.0 - alpha - beta;
    y.first = cos(gamma) * b, y.second = sin(gamma) * b;
    if (y.first - w > eps || y.second - h > eps || y.first < -eps || y.second < -eps) return 0;
    return 1;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        Point x, y, z;
        int a, b, c;
        scanf("%d%d%d%d%d", &w, &h, &a, &b, &c);
        if (solve(b, c, a, x, y) || solve(c, b, a, y, x)) {
            z.first = z.second = 0; goto mark;
        }
        if (solve(a, c, b, x, z) || solve(c, a, b, z, x)) {
            y.first = y.second = 0; goto mark;
        }
        if (solve(a, b, c, y, z) || solve(b, a, c, z, y)) {
            x.first = x.second = 0; goto mark;
        }
mark:
        printf("%.10f %.10f %.10f %.10f %.10f %.10f\n", x.first, x.second, y.first, y.second, z.first, z.second);
    }
    return 0;
}