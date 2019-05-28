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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

int a[6];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int ans = 1;
        for (int i = 1; i <= 5; i++) a[i] = 0;
        for (int i = 1; i <= 5; i++) {
            int x; scanf("%d", &x); a[x]++;
        }
        for (int i = 1; i <= 5; i++)
            if (a[i] > a[ans]) ans = i;
        printf("%d\n", ans);
    }
    return 0;
}