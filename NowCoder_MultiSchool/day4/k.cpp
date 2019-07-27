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

const int maxn = 1e5 + 10;
char s[maxn];
int len, mod3[maxn];

int main() {
    scanf("%s", s + 1);
    len = strlen(s + 1);
    ll ans = 0;
    rep1(i, 1, len) mod3[i] = (s[i] - '0') % 3;
    set<int>pos; pos.clear();

    printf("%lld\n", ans);
    return 0;
}