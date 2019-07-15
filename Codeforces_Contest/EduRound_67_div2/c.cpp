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

const int maxn = 1e3 + 10;
struct Interval {
    int t, l, r;
    Interval() {}
    Interval(int a, int b, int c): t(a), l(b), r(c) {}
} v[maxn];
int n, m, p = 0, ans = 1e8, flag = 1, a[maxn], b[maxn];

int main() {
    scanf("%d%d", &n, &m);
    rep1(i, 1, m) {
        scanf("%d%d%d", &v[i].t, &v[i].l, &v[i].r);
        if (v[i].t == 1)
            rep0(j, v[i].l, v[i].r) a[j] = 1; // sign
    }
    rep1(i, 1, m)
    if (!v[i].t) {
        flag = 0;
        rep0(j, v[i].l, v[i].r)
        if (!a[j]) {
            flag = 1; break;
        }
        if (!flag)
            return puts("NO");
    }
    puts("YES");
    rep1(i, 1, n) printf("%d ", a[i - 1] ? ans : --ans);
    puts("");
    return 0;
}