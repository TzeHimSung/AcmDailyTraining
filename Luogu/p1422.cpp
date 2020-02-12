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

int a;
double ans = 0;

int main() {
    scanf("%d", &a);
    if (a <= 150) {
        ans = a * 0.4463;
    } else if (a > 150 && a <= 400) {
        ans = 150 * 0.4463 + (a - 150) * 0.4663;
    } else {
        ans = 150 * 0.4463 + 250 * 0.4663 + (a - 400) * 0.5663;
    }
    printf("%.1f\n", ans);
    return 0;
}