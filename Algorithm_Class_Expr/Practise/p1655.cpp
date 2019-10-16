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

const int maxn = 105;
int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        double maxx = DBL_MIN, minn = DBL_MAX, sum = 0, x;
        for (int i = 1; i <= n; i++) {
            scanf("%lf", &x);
            maxx = max(maxx, x); minn = min(minn, x); sum += x;
        }
        printf("%.2f %.2f %.2f\n", maxx, minn, sum / n);
    }
    return 0;
}