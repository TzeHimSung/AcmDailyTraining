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

const int maxn = 2e5 + 10;
int n, m, a[maxn] = {0}, b[maxn] = {0};

int main() {
    scanf("%d%d", &n, &m);
    rep0(i, 0, n) {
        cin >> a[i];
        sort(a, a + i);
        ll sum = 0;
        rep1(j, 0, i)
        if (sum + a[i] + a[j] > m) {
            b[i] = i - j;
            break;
        } else sum += a[j];
    }
    rep0(i, 0, n) printf("%d ", b[i]);
    puts("");
    return 0;
}