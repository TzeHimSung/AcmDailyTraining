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

int n, d, e;

int main() {
    scanf("%d%d%d", &n, &d, &e);
    int dollarUnit = d, euroUnit = e * 5, ans = n;
    for (int numOfDollar = 0; numOfDollar <= n / dollarUnit; numOfDollar++) {
        int remainRubles = n - numOfDollar * dollarUnit;
        remainRubles -= remainRubles / euroUnit * euroUnit;
        ans = min(ans, remainRubles);
    }
    for (int numOfEuro = 0; numOfEuro <= n / euroUnit; numOfEuro += 5) {
        int remainRubles = n - numOfEuro * euroUnit;
        remainRubles -= remainRubles / dollarUnit * dollarUnit;
        ans = min(ans, remainRubles);
    }
    printf("%d\n", ans);
    return 0;
}
