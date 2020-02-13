/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(p,b) sort(p+1,p+1+b)
#define rep1(i,p,b) for(int i=p;i<=b;++i)
#define rep0(i,p,b) for(int i=p;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

int n;
const int p[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 21, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int check(int x) {
    if (x == 0 || x == 1) return 0;
    for (int i = 2; i <= (int)sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 25; i++) {
        for (int j = 1; j <= 25; j++) {
            if (check(n - p[i] - p[j])) {
                printf("%d %d %d\n", p[i], p[j], n - p[i] - p[j]);
                return 0;
            }
        }
    }
    return 0;
}