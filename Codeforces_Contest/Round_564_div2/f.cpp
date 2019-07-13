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
int n, x, y, a[maxn], b[maxn], tot = 0;
struct Door {
    int a, b, c, d;
    Door() {}
    Door(int x, int y, int p, int q): a(x), b(y), c(p), d(q) {}
};
Door door[maxn];

int main() {
    scanf("%d", &n);
    rep1(i, 1, n) scanf("%d", &a[i]);
    rep1(i, 1, n) scanf("%d", &b[i]);
    rep1(i, 1, n) {
        if (a[i] == i && b[i] == i) continue;
        rep1(j, i, n)
        if (a[j] == i) {
            swap(a[i], a[j]);
            x = j;
            break;
        }
        rep1(j, i, n)
        if (b[j] == i) {
            swap(b[i], b[j]);
            y = j;
            break;
        }
        door[++tot] = Door(x, i, i, y);
    }
    printf("%d\n", tot);
    rep1(i, 1, tot) printf("%d %d %d %d\n", door[i].a, door[i].b, door[i].c, door[i].d);
    return 0;
}