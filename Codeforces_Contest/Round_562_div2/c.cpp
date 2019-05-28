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

const int maxn = 3e5 + 10;
int n, m, a[maxn];

int main() {
    scanf("%d%d", &n, &m);
    rep0(i, 0, n) scanf("%d", &a[i]);
    int l = -1, r = m;
    while (l < r - 1) {
        int mid = l + r >> 1, prev = 0, flag = 1;
        rep0(i, 0, n) {
            int lpos = a[i], rpos = a[i] + mid;
            if ((lpos <= prev && prev <= rpos) || (lpos <= prev + m && prev + m <= rpos))
                continue;
            if (a[i] > prev) prev = a[i];
            else {
                flag = 0;
                break;
            }
        }
        if (flag) r = mid; else l = mid;
    }
    printf("%d\n", r);
    return 0;
}