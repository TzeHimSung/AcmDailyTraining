#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for (int i=a;i<=b;i++)
#define eps 1e-12
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curpos<<1
#define rson curpos<<1|1

using namespace std;

const int maxn = 1e5 + 10;
struct Line {
    double k, b; //线段所在直线的k,b
    int l, r, flag; //l,r为该线段两端点的x坐标，也就是函数的定义域
    Line() {}
    Line(int a, int b, double c, double d) {
        this->l = a, this->r = b, this->k = c, this->b = d;
    }
    double calc(const int pos)const { //返回线段在x处的y值
        return k * pos + b;
    }
    int cross(const Line &rhs)const { //求两线段交点的横坐标
        return floor((b - rhs.b) / (rhs.k - k));
    }
} segt[maxn << 2];

int n; char op[10];

void build(int curpos, int curl, int curr) {
    segt[curpos].k = segt[curpos].b = 0;
    segt[curpos].l = 1; segt[curpos].r = (int)5e4;
    if (curl == curr) return;
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
}

void update(int curpos, int curl, int curr, Line k) { //
    if (k.l <= curl && curr <= k.r) {
        if (k.calc(curl) - segt[curpos].calc(curl) > eps && k.calc(curr) - segt[curpos].calc(curr) > eps) segt[curpos] = k;
        else if (k.calc(curl) - segt[curpos].calc(curl) > eps || k.calc(curr) - segt[curpos].calc(curr) > eps) {
            int mid = curl + curr >> 1;
            if (k.calc(mid) - segt[curpos].calc(mid) > eps) {
                Line tmp = k; k = segt[curpos]; segt[curpos] = tmp;
            }
            if (k.cross(segt[curpos]) - mid < -eps) update(lson, curl, mid, k);
            else update(rson, mid + 1, curr, k);
        }
    } else {
        int mid = curl + curr >> 1;
        if (k.l <= mid) update(lson, curl, mid, k);
        if (k.r > mid) update(rson, mid + 1, curr, k);
    }
}

double query(int curpos, int curl, int curr, int x) {
    if (curl == curr) return segt[curpos].calc(x);
    int mid = curl + curr >> 1;
    double ans = segt[curpos].calc(x);
    if (x <= mid) return max(ans, query(lson, curl, mid, x));
    else return max(ans, query(rson, mid + 1, curr, x));
}

int main() {
    scanf("%d", &n);
    build(1, 1, (int)5e4);
    rep1(i, 1, n) {
        scanf("%s", op);
        if (op[0] == 'P') {
            double s, p;
            scanf("%lf%lf", &s, &p);
            Line now = Line(1, 50000, p, s - p); //第1天的收益是s,第0天的收益自然是s-p
            update(1, 1, (int)5e4, now);
        } else {
            int x; scanf("%d", &x);
            int ans = (int)floor(query(1, 1, (int)5e4, x) / 100);
            printf("%d\n", ans);
        }
    }
    return 0;
}