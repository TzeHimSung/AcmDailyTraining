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

const int maxn = 5e3 + 10;
struct Apple {
    int h, s;
    bool operator<(const Apple &rhs)const {
        return s < rhs.s;
    }
} a[maxn];
int n, s, t, b, ans = 0;

int main() {
    scanf("%d%d%d%d", &n, &s, &t, &b);
    b += t;
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i].h, &a[i].s);
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i].h <= b && s >= a[i].s) {
            ans++;
            s -= a[i].s;
        }
    }
    printf("%d\n", ans);
    return 0;
}