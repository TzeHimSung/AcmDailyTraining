#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;

struct Point {
    long long x, y;
    int num;
    bool operator <(const Point &p)const {
        return x != p.x ? x < p.x : y < p.y;
    }
    Point operator -(const Point &p)const {
        return { x - p.x, y - p.y };
    }
    Point Rotate() {
        return { -y, x };
    }
} w[4400], P[4400], st[4400];
long long Z[4400];
int n;

long long Mul(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

long long getArea(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void Solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &w[i].x, &w[i].y);
    }
    // 按x和y排序
    sort(w, w + n);
    for (int i = 0; i < n; i++) w[i].num = i; // 给点编号
    int cnt = 0, top = 0;
    // 求凸包？
    for (int i = 0; i < n; i++) {
        while (top > 1 && getArea(st[top - 1], st[top], w[i]) <= 0) top--;
        st[++top] = w[i];
    }
    for (int i = 1; i < top; i++) P[cnt++] = st[i];
    top = 0;
    for (int i = 0; i < n; i++) {
        while (top > 1 && getArea(st[top - 1], st[top], w[i]) >= 0)top--;
        st[++top] = w[i];
    }
    for (int i = top; i > 1; i--) P[cnt++] = st[i];
    if (cnt <= 2) {
        puts("0");
        return;
    }
    long long res = 0;
    for (int i = 0; i < cnt; i++) {
        Point V1 = P[(i + 1) % cnt] - P[i];
        Point V2 = V1.Rotate();
        long long Mx2 = -5e18;
        for (int j = 0; j < cnt; j++) {
            long long t = Mul(V2, P[j]);
            Z[j] = t;
            if (Mx2 < t)Mx2 = t;
        }
        for (int j = 0; j < cnt; j++) {
            if (Z[j] == Mx2) {
                Point VV = (P[j] - P[i]).Rotate();
                long long Mn = 5e18, Mx = -5e18;
                for (int k = 0; k < n; k++) {
                    if (k == P[i].num || k == P[j].num)continue;
                    long long t = Mul(VV, w[k]);
                    if (Mn > t)Mn = t;
                    if (Mx < t)Mx = t;
                }
                res = max(res, Mx - Mn);
            }
        }
    }
    if (res % 2)printf("%lld.5\n", res / 2);
    else printf("%lld\n", res / 2);
}

int main() {
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        Solve();
    }
}