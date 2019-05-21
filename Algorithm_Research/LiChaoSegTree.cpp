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
//思来想去，李超线段树的节点名字还是叫Interval而不是Line
//因为这棵线段树以区间为核心，维护的是每一个区间的最优势线段
//写得很长是为了方便初学者理解
struct Interval {
    double k, b; //区间最优势线段的k,b
    int l, r, flag; //l,r为区间。flag为该区间已经记录最优势线段标记。
    Interval() {}
    Interval(int a, int b, double c, double d) {
        this->l = a, this->r = b, this->k = c, this->b = d;
    }
    double calc(const int pos)const { //返回线段在x处的y值
        return k * pos + b;
    }
    int cross(const Interval &rhs)const { //求两线段交点的横坐标
        return floor((b - rhs.b) / (rhs.k - k));
    }
} segt[maxn << 2];

int n; char op[10];

//因为李超线段树以区间为核心，所以每次建树时main函数调用build(xOy平面最左端,xOy平面最右端，1);
void build(int curpos, int curl, int curr) {
    segt[curpos].k = segt[curpos].b = 0;
    segt[curpos].l = 1; segt[curpos].r = (int)5e4;
    if (curl == curr) return;
    int mid = curl + curr >> 1;
    build(lson, curl, mid); build(rson, mid + 1, curr);
}

//插入新线段并维护所有区间最优势线段信息
void update(int curpos, int curl, int curr, Interval k) {
    if (k.l <= curl && curr <= k.r) { //被插入线段完全覆盖了当前区间
        //如果当前区间还没有最优势线段，直接标记
        if (!segt[curpos].flag) segt[curpos] = k, segt[curpos].flag = 1;
        //如果被插入线段优于区间最优势线段，更新之
        else if (k.calc(curl) - segt[curpos].calc(curl) > eps && k.calc(curr) - segt[curpos].calc(curr) > eps) segt[curpos] = k;
        //如果被插入线段只有一端优于最优势线段，则检查
        else if (k.calc(curl) - segt[curpos].calc(curl) > eps || k.calc(curr) - segt[curpos].calc(curr) > eps) {
            int mid = curl + curr >> 1;
            if (k.calc(mid) - segt[curpos].calc(mid) > eps) { //这里很关键，要看区间中点哪条线段更优
                Interval tmp = k; k = segt[curpos]; segt[curpos] = tmp;
            }
            if (k.cross(segt[curpos]) - mid < -eps) update(lson, curl, mid, k);
            else update(rson, mid + 1, curr, k);
        }
    } else { //若不优于最优势线段，则检查左右区间
        int mid = curl + curr >> 1;
        if (k.l <= mid) update(lson, curl, mid, k);
        if (k.r > mid) update(rson, mid + 1, curr, k);
    }
}

//查询区间最优势线段在x处取值
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
            Interval newline = Interval(1, 50000, p, s - p); //第1天的收益是s,第0天的收益自然是s-p
            update(1, 1, (int)5e4, newline);
        } else {
            int x; scanf("%d", &x);
            int ans = (int)floor(query(1, 1, (int)5e4, x) / 100);
            printf("%d\n", ans);
        }
    }
    return 0;
}