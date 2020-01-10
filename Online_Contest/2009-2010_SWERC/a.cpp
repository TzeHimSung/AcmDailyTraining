#include<bits/stdc++.h>
using namespace std;
typedef pair<double, double> pii;
#define ff first
#define ss second
int n;
pii p[50010];
double eps = 1e-10;

double getDis(pii &x, pii &y) {
    return sqrt((x.ff - y.ff) * (x.ff - y.ff) + (x.ss - y.ss) * (x.ss - y.ss));
}

double f(double x) {
    double res = 0;
    pii currP = make_pair(x, 0);
    for (int i = 1; i <= n; i++) {
        double cur = getDis(p[i], currP);
        if (cur - res > eps)res = cur;
    }
    return res;
}

int main() {
    while (scanf("%d", &n) == 1 && n) {
        double maxL = 1e9, maxR = -1e9;
        for (int i = 1; i <= n; i++) {
            scanf("%lf%lf", &p[i].ff, &p[i].ss);
            maxL = min(maxL, p[i].ff), maxR = max(maxR, p[i].ff);
        }
        double l = maxL, r = maxR;
        while (r - l > eps) {
            double delta = (r - l) / 3.0;
            double mid1 = l + delta, mid2 = l + delta * 2.0;
            double f1 = f(mid1), f2 = f(mid2);
            if (f1 >= f2) l = mid1;
            else r = mid2;
        }
        printf("%.9f %.9f\n", l, f(l));
    }
}
