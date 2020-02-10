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

const int maxn = 1e6 + 10;
int n, pos[maxn], p = 0;
ll a[maxn];

int main() {
    a[0] = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        a[i] = a[i - 1] + x;
    }
    for (int i = 1; i <= n; i++) {
        while (p && 1.0 * (a[pos[p]] - a[pos[p - 1]]) / (pos[p] - pos[p - 1]) - 1.0 * (a[i] - a[pos[p - 1]]) / (i - pos[p - 1]) > 1e-12)
            p--;
        pos[++p] = i;
    }
    for (int i = 1; i <= p; i++) {
        double x = 1.0 * (a[pos[i]] - a[pos[i - 1]]) / (pos[i] - pos[i - 1]);
        for (int j = pos[i - 1]; j < pos[i]; j++) printf("%.10f\n", x);
    }
    return 0;
}