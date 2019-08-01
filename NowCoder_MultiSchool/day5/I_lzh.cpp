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

#define Point pair<double, double>
const double pi = acos(-1.0);

bool judge(int a, int b, int w, int h, Point &x, Point &y, int c) {
    double beta = 0;
    if (a <= h) x.first = 0, x.second = a; // 边a可以靠到y轴上
    else x.first = sqrt(a * a - h * h), x.second = h, beta = acos(1.0 * h / (a));
    double alpha = acos(1.0 * (a * a + b * b - c * c) / (2.0 * a * b));
    alpha = pi / 2.0 - beta - alpha; // 反三角函数算出左下角两个角的度数，再算出余角
    y.first = cos(alpha) * b, y.second = sin(alpha) * b;
    if (y.first - w > eps || y.second - h > eps || y.first < -eps || y.second < -eps) return false;
    return true;
}

int w, h, a, b, c;
Point x, y, z;

void solve() {
    if (judge(b, c, w, h, x, y, a) || judge(c, b, w, h, y, x, a)) {
        z.first = z.second = 0;
        return;
    }
    if (judge(a, c, w, h, x, z, b) || judge(c, a, w, h, z, x, b)) {
        y.first = y.second = 0;
        return;
    }
    if (judge(a, b, w, h, y, z, c) || judge(b, a, w, h, z, y, c)) {
        x.first = x.second = 0;
        return;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d%d", &w, &h, &a, &b, &c);
        solve();
        printf("%.8lf %.8lf %.8lf %.8lf %.8lf %.8lf\n", x.first, x.second, y.first, y.second, z.first, z.second);
    }
}