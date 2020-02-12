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

int save = 0, boom = 0, curr = 0;

int main() {
    for (int i = 1; i <= 12; i++) {
        curr += 300;
        int x; scanf("%d", &x);
        if (curr < x) {
            boom = i;
        }
        if (boom) continue;
        save += 100 * ((curr - x) / 100);
        curr -= 100 * ((curr - x) / 100) + x;
    }
    if (!boom) printf("%d\n", (int)(1.0 * save * 1.2 + curr));
    else printf("-%d\n", boom);
    return 0;
}