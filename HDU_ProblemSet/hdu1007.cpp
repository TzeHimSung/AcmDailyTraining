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

const int maxn = 1e5 + 10;
struct Point {
    double x, y;
    Point() {}
    Point(double _x, double _y): x(_x), y(_y) {}

    bool operator<(const Point &rhs)const {
        return x != rhs.x ? x < rhs.x : y < rhs.y;
    }
} a[maxn];
int n;

double distance(const Point &a, const Point &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double solve(int curl, int curr) {
    if (curl == curr) return -1;
    if (curr - curl == 1) return distance(a[curl], a[curr]);
    int mid = curl + curr >> 1;
    double d1 = solve(curl, mid), d2 = solve(mid, curr), minD = DBL_MAX;
    if (d1 > 0) minD = min(minD, d1);
    if (d2 > 0) minD = min(minD, d2);
    // bugs
    int lpos = lower_bound(a + 1, a + 1 + n, a[mid] - minD) - a;
    int rpos = upper_bound(a + 1, a + 1 + n, a[mid] + minD) - a;
    for (int i = lpos; i <= rpos; i++)
        for (int j = i + 1; j <= rpos; j++)
            minD = min(minD, distance(a[i], a[j]));
    return minD;
}

int main() {
    while (~scanf("%d", &n) && n) {
        rep1(i, 1, n) scanf("%lf%lf", &a[i].x, &a[i].y);
        sot(a, n);
        printf("%.3f\n", solve(1, n));
    }
    return 0;
}