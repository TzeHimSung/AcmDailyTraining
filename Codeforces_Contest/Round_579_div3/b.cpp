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

const int maxn = 500;
int n, a[maxn], t;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n); n = n * 4;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        int p = 1, q = n, area = -1, flag = 1;
        while (p < q) {
            if (area == -1) area = a[p] * a[q];
            else if (a[p]*a[q] != area) {
                flag = 0; break;
            }
            if (a[p] != a[p + 1] || a[q] != a[q - 1]) {
                flag = 0; break;
            }
            p += 2, q -= 2;
        }
        if (flag) puts("YES"); else puts("NO");
    }
    return 0;
}