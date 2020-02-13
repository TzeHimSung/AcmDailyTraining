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

const int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n, ans = 0;

int get(int x) {
    if (x < 10) return cost[x];
    int ret = 0;
    while (x) {
        ret += cost[x % 10];
        x /= 10;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    for (int a = 0; a < 1000; a++) {
        for (int b = 0; b < 1000; b++) {
            for (int c = 0; c < 1000; c++) {
                // if (a == 0 && b == 4 && c == 4) {
                //     printf("!");
                // }
                if (a + b == c && get(a) + get(b) + get(c) == n - 4) {
                    ans++;
                    // cout << a << " " << b << " " << c << endl;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}