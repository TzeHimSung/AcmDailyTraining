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

int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    do {
        int x = a[0] * 100 + a[1] * 10 + a[2];
        int y = a[3] * 100 + a[4] * 10 + a[5];
        int z = a[6] * 100 + a[7] * 10 + a[8];
        if (y / x == 2 && y % x == 0 && z / x == 3 && z % x == 0) printf("%d %d %d\n", x, y, z);
    } while (next_permutation(a, a + 9));
    return 0;
}