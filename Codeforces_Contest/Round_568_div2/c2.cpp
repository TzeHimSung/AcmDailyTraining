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
int n, m, a[maxn], b[maxn], time[110];

int main() {
    scanf("%d%d", &n, &m);
    rep0(i, 0, n) scanf("%d", &a[i]);
    rep0(i, 0, 110) time[i] = 0;
    int s = 0, sum = 0, ss = 0, delta1 = 0, delta2 = 0;
    rep0(i, 0, n) {
        s += a[i];
        if (s > m) {
            delta1 = s - m;
            ss = 0;
            for (int j = 100; j >= 1; j--) // enum each time slot
                if (time[j]) {
                    sum += j * time[j];
                    ss += time[j];
                    if (sum > delta1) {
                        delta2 = sum - delta1;
                        ss -= delta2 / j;
                        break;
                    }
                }
            b[i] = ss;
            sum = 0;
        } else b[i] = 0;
        time[a[i]]++;
    }
    rep0(i, 0, n) printf("%d ", b[i]);
    puts("");
    return 0;
}