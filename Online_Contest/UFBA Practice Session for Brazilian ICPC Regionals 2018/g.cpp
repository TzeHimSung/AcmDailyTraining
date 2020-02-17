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

const int maxn = 1e5 + 10;
const double pi = acos(-1);
struct Ship {
    int visiable;
    double beta;
    ll x, y;
} a[maxn];
int n;
double x, alpha, t, ans[maxn];
ll d;

void fix(double &x) {
    if (x < 0) x += 360;
    if (x >= 360) x -= 360;
}

int main() {
    scanf("%d%lf", &n, &x);
    scanf("%lf%lf%lld", &alpha, &t, &d);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &a[i].x, &a[i].y);
        a[i].visiable = a[i].x * a[i].x + a[i].y * a[i].y <= d * d;
        a[i].beta = atan2(a[i].y, a[i].x) / pi * 180;
        fix(a[i].beta); a[i].beta += alpha / 2; fix(a[i].beta);
    }
    ll round = (ll)floor(x / t);
    double timePerRound = alpha / 360 * t, remainTime = x - round * t;
    for (int i = 1; i <= n; i++) {
        ans[i] = round * timePerRound;
        if (a[i].beta < alpha && round) ans[i] -= (alpha - a[i].beta) / alpha * timePerRound;
    }
    double minAlpha = remainTime / t * 360, maxAlpha = minAlpha + alpha;
    for (int i = 1; i <= n; i++) {
        if (a[i].beta < minAlpha) {
            ans[i] += timePerRound;
            if (a[i].beta < alpha && !round) ans[i] -= (alpha - a[i].beta) / alpha * timePerRound;
        } else if (a[i].beta < maxAlpha) {
            if (!round) ans[i] += (maxAlpha - alpha) / alpha * timePerRound;
            else ans[i] += (maxAlpha - a[i].beta) / alpha * timePerRound;
        }
        // 如果转过去还大于360
        if (maxAlpha > 360) {
            double remainMaxAlpha = maxAlpha - 360;
            if (a[i].beta < remainMaxAlpha) ans[i] += (remainMaxAlpha - a[i].beta) / alpha * timePerRound;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!a[i].visiable) ans[i] = 0;
        printf("%.11f\n", ans[i]);
    }
    return 0;
}