/* basic header */
#include <iostream>
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

const int maxn = 2e5 + 10;
struct Car {
    int l, s, v;
} car[maxn];

int n;

int check(double x) {
    double currS = car[n].s - car[n].v * x; // 最前面的车行驶x时间之后离stopline的距离，也可以认为是一个“容忍距离”，决定了容忍多少辆车相撞
    for (int i = n - 1; i >= 0; i--) { // 遍历前面的每一辆车
        // 如果 前一辆车行驶x时间之后离stopline的距离 比 最前面的车行驶x时间之后离stopline的距离塞下下一辆车 还短
        // 那么当前这辆车一定不会和身后的车相撞，那么允许后面的车走过stopline
        if (car[i].s - car[i].v * x <= currS + car[i + 1].l) currS += car[i + 1].l;
        else currS = car[i].s - car[i].v * x; // 否则会相撞，答案更新为当前的车在前面无阻碍的情况下行驶x时间离stopline的距离
    }
    return currS <= eps; // 如果小于等于0，说明行驶x时间后必然可以到达stopline
}

int main() {
    while (~scanf("%d", &n)) {
        rep1(i, 0, n) scanf("%d", &car[i].l);
        rep1(i, 0, n) scanf("%d", &car[i].s);
        rep1(i, 0, n) scanf("%d", &car[i].v);
        double l = 0, r = 1e18; // 二分到达时间
        while (r - l > eps) {
            double mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid;
        }
        printf("%.6f\n", r);
    }
    return 0;
}