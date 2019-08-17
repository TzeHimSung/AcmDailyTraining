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
int n, r, cntX[maxn * 3], cntY[maxn * 3], res;
struct Point {
    int x, y;
    bool operator<(const Point &rhs)const {
        return x > rhs.x;
    }
} a[maxn], sum[maxn];

int main() {
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        cntX[a[i].x]++;
    }
    for (int i = 0; i < maxn; i++) {
        sum[i].x = cntX[i] + cntX[i + r] + cntX[i + r * 2];
        sum[i].y = i;
    }
    sort(sum, sum + maxn);
    for (int i = 0; i < 100; i++) {
        memset(cntY, 0, sizeof(cntY));
        for (int j = 0; j < n; j++)
            if (a[j].x != sum[i].y && a[j].x != sum[i].y + r && a[j].x != sum[i].y + r * 2)
                cntY[a[j].y]++;
        int my = 0;
        for (int j = 0; j < maxn; j++)
            my = max(my, cntY[j] + cntY[j + r] + cntY[j + r * 2]);
        res = max(res, my + sum[i].x);
    }
    printf("%d\n", res);
    return 0;
}
