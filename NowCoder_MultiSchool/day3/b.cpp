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
int n, a[maxn], b[maxn], cnt1 = 0, cnt2 = 0;

int check(int x) {
    x *= 2;
    rep1(i, x, n)
    if (a[i] - a[i - x] == b[i] - b[i - x]) return 1;
    return 0;
}

int main() {
    a[0] = b[0] = 0;
    scanf("%d", &n);
    rep1(i, 1, n) {
        int x; scanf("%1d", &x);
        a[i] = a[i - 1], b[i] = b[i - 1];
        if (x) cnt1++, a[i]++;
        else cnt2++, b[i]++;
    }
    int l = 1, r = n / 2;
    while (l <= r) {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d %d\n", 2 * r, 2 * min(cnt1, cnt2));
    return 0;
}