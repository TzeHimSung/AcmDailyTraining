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

int n;

int check(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    if (sum % 4 == 0) return 1; else return 0;
}

int main() {
    cin >> n;
    for (int i = n;; i++) {
        if (check(i)) return printf("%d\n", i), 0;
    }
    return 0;
}