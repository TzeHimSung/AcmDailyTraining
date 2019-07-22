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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

// const int maxn = 1e6 + 10, maxm = 2e7 + 10;
const int maxn = 10, maxm = 20;
ll sum = 0;
int s[maxm], l[maxn], r[maxn], p[maxn];
int n, x = 0, now = 0, zero = 10, k = 0, st = zero, L = zero, R = zero;

// 只包含1的区间称为1区间，只包含0的区间称为0区间
int main() {
    scanf("%d", &n);
    rep1(i, 1, n) scanf("%d%d", &l[i], &r[i]);
    // p是前缀和，维护当前1区间和前面的0区间抵消之后剩下1的个数
    rep1(i, 1, n) p[i] = p[i - 1] + (r[i] - l[i] + 1) - (l[i] - r[i - 1] - 1);
    for (int i = n - 1; i >= 1; i--) p[i] = max(p[i], p[i + 1]);
    s[zero] = 1;
    rep1(i, 1, n) {
        while (x < l[i]) {
            if (!now && k - p[i] < l[i] && k > p[i]) {
                x += k - p[i];
                k = p[i];
                st = L = zero;
                R = zero - 1;
            }
            x++, k--, st--;
            if (st < L) {
                L--; s[st] = 0;
            }
            now -= s[st]++;
            sum += now;
        }
        while (x <= r[i]) {
            x++, k++;
            now += s[st++];
            sum += now;
            if (st > R) {
                R++;
                s[st] = 0;
            }
            s[st]++;
        }
    }
    while (now > 0 && x < 1e9 && st >= 0 && st <= 2 * zero) {
        x++;
        now -= s[--st]++;
        sum += now;
    }
    printf("%lld\n", sum);
    return 0;
}