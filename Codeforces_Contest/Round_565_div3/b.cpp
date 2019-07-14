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

int t, n;

int main() {
    scanf("%d", &t);
    while (t--) {
        int a = 0, b = 0, c = 0;
        scanf("%d", &n);
        while (n--) {
            int x; scanf("%d", &x);
            if (x % 3 == 0) a++;
            else if (x % 3 == 1) b++;
            else if (x % 3 == 2) c++;
        }
        int ans = a, tmp = min(b, c);
        ans += tmp, b -= tmp, c -= tmp;
        ans += b / 3, ans += c / 3;
        printf("%d\n", ans);
    }
    return 0;
}