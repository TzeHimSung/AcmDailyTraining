// prim by czq

/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
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

const int maxn = 110;
double __map[maxn][maxn], sign[maxn], sum = 0;
int x[maxn], y[maxn], vis[maxn], n;

double getDistance(int i, int j) {
    return sqrt(1.0 * ((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])));
}

void prim() {
    double min, sum = 0;
    int pos = 1;
    for (int i = 0; i < maxn; i++) vis[i] = 0;
    vis[1] = 1;
    for (int i = 1; i <= n; i++) sign[i] = __map[pos][i];
    for (int i = 1; i < n; i++) {
        min = int_inf;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && sign[j] < min) {
                min = sign[j];
                pos = j;
            }
        // no solution
        if (min == int_inf) {
            puts("no!");
            return;
        }
        vis[pos] = 1;
        sum += min;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && sign[j] > __map[pos][j])
                sign[j] = __map[pos][j];
    }
    printf("%.1f\n", sum * 100);
    return;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
        memset(__map, 0, sizeof(__map));
        // calc line
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                __map[i][j] = __map[j][i] = getDistance(i, j);
                if (__map[i][j] < 10 || __map[i][j] > 1000)
                    __map[i][j] = __map[j][i] = int_inf;
            }
        }
        prim();
    }
    return 0;
}