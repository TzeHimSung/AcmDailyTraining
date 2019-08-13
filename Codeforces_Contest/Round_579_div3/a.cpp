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

int q;
int a[300];

int main() {
    scanf("%d", &q);
    while (q--) {
        int n; scanf("%d", &n);
        int p, k;
        rep1(i, 1, n) {
            scanf("%d", &a[i]);
            if (a[i] == 1) k = p = i;
        }
        if (n == 1) {
            puts("YES");
            continue;
        }
        int flag1 = 1, flag2 = 1, last = a[k];
        while (1) {
            p++;
            if (p > n) p = 1;
            if (a[p] - last != 1) {
                flag1 = 0; break;
            }
            last = a[p];
            if (a[p] == n) break;
        }
        last = a[k]; p = k;
        while (1) {
            p--;
            if (!p) p = n;
            if (a[p] - last != 1) {
                flag2 = 0; break;
            }
            last = a[p];
            if (a[p] == n) break;
        }
        if (flag1 || flag2) puts("YES"); else puts("NO");
    }
    return 0;
}