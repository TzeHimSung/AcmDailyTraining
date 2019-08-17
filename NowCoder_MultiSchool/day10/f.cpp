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
int n, r, fx[maxn * 3], fy[maxn * 3], res;
struct Node {
    int x, y;
    bool operator<(const Node &rhs)const {
        return x > rhs.x;
    }
} a[maxn], w[maxn];

int main() {
    scanf("%d%d", &n, &r);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        fx[a[i].x]++;
    }
    for (int i = 0; i < maxn; i++) {
        w[i].x = fx[i] + fx[i + r] + fx[i + r * 2];
        w[i].y = i;
    }
    sort(w, w + maxn);
    for (int i = 0; i < 100; i++) {
        memset(fy, 0, sizeof(fy));
        for (int j = 0; j < n; j++)
            if (a[j].x != w[i].y && a[j].x != w[i].y + r && a[j].x != w[i].y + r * 2)
                fy[a[j].y]++;
        int my = 0;
        for (int j = 0; j < maxn; j++)
            my = max(my, fy[j] + fy[j + r] + fy[j + r * 2]);
        res = max(res, my + w[i].x);
    }
    printf("%d\n", res);
    return 0;
}
