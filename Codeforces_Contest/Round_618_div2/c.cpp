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
int n, a[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int j = 30; ~j; j--) {
        int cnt = 0, pos;
        for (int i = 1; i <= n; i++)
            if ((a[i] >> j) & 1) {
                cnt++;
                pos = i;
            }
        if (cnt == 1) {
            printf("%d ", a[pos]);
            for (int i = 1; i <= n; i++) {
                if (i != pos) printf("%d ", a[i]);
            }
            puts("");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", a[i]);
    puts("");
    return 0;
}