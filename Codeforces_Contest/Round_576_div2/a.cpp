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
int n, x, y, a[maxn];

int main() {
    scanf("%d%d%d", &n, &x, &y);
    rep1(i, 1, n) scanf("%d", &a[i]);
    rep1(i, 1, n) {
        int flag1 = 1, flag2 = 1;
        for (int j = i - 1; j >= 1 && j >= i - x; j--)
            if (a[j] < a[i]) {
                flag1 = 0; break;
            }
        for (int j = i + 1; j <= n && j <= i + y; j++)
            if (a[j] < a[i]) {
                flag2 = 0; break;
            }
        if (flag1 && flag2) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}