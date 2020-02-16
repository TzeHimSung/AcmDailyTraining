#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> pii;

const double g = 10.0;
const double pi = acos(-1.0);

long double ansl, ansr;
int n, v, l, r;
void solve45(double x, double y) {
    ansl = ansr = -1;
    if (l > 45)
        return;
    long double L = l * pi / 180.0, R = min(45, r) * pi / 180.0;
    long double st = (long double)v * v / g * sin(2.0 * L),
                end = (long double)v * v / g * sin(2.0 * R);
    if (l == 0)
        st = 0;
    x = max((long double)x, st), y = min((long double)y, end);
    if (x > y)
        return;

    long double res1 = asin((long double)g * x / v / v);
    res1 /= 2.0;

    long double res2 = asin((long double)g * y / v / v);
    res2 /= 2.0;

    ansl = max(L, res1), ansr = min(R, res2);
}
void solve90(double x, double y) {
    ansl = ansr = -1;
    if (r < 45)
        return;
    long double L = max(45, l) * pi / 180.0, R = r * pi / 180.0;
    long double st = (long double)v * v / g * sin(2.0 * R),
                end = (long double)v * v / g * sin(2.0 * L);
    if (r == 90)
        st = 0;
    x = max((long double)x, st), y = min((long double)y, end);
    //printf("%lf %lf\n", x, y);
    if (x > y)
        return;

    long double res1 = asin((long double)g * y / v / v);
    res1 = (pi - res1) / 2.0;

    long double res2 = asin((long double)g * x / v / v);
    res2 = (pi - res2) / 2.0;

    ansl = max(L, res1), ansr = min(R, res2);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &n, &v, &l, &r);
        if (l == r) {
            long double should = (long double)v * v / g * sin(2.0 * l * pi / 180.0);
            while (n--) {
                double x, y;
                scanf("%lf%lf", &x, &y);
                if (should - x >= -1e-6 && y - should >= -1e-6)
                    printf("1.0000\n");
                else
                    printf("0.0000\n");
            }
        } else
            while (n--) {
                double x, y;
                scanf("%lf%lf", &x, &y);
                double ans = 0;

                solve45(x, y);
                if (ansl != -1)
                    ans += ansr - ansl;

                solve90(x, y);
                if (ansl != -1)
                    ans += ansr - ansl;

                printf("%.4lf\n", abs(ans / (pi * (r - l) / 180.0)));
            }
    }
}