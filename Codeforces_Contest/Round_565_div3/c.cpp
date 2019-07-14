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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 5e5 + 10;
int n, a[7], ans = 0;

int main() {
    scanf("%d", &n);
    rep1(i, 1, 6) a[i] = 0;
    rep1(i, 1, n) {
        int x; scanf("%d", &x);
        if (x == 4) a[1]++;
        else if (x == 8)
                if (a[1] > a[2])a[2]++; else ans++;
        else if (x == 15)
                if (a[2] > a[3]) a[3]++; else ans++;
        else if (x == 16)
                if (a[3] > a[4]) a[4]++; else ans++;
        else if (x == 23)
                if (a[4] > a[5]) a[5]++; else ans++;
        else if (a[5] > a[6]) a[6]++; else ans++;
    }
    int minn = int_inf;
    rep1(i, 1, 6) minn = min(minn, a[i]);
    rep1(i, 1, 6) ans += a[i] - minn;
    printf("%d\n", ans);
    return 0;
}