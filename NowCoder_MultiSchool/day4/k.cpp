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

// const int maxn = 1e5 + 10;
const int maxn = 10;
char s[maxn];
int n, pre[maxn], cnt[3];

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    rep1(i, 1, n) pre[i] = (pre[i - 1] + s[i] - '0') % 3;
    ll ans = 0;
    rep1(i, 1, n) {
        if (s[i] == '0') {
            ans++; // 算单独0
            if (s[i - 1] == '0') ans += cnt[pre[i - 1]]; // 如果前一位也是0，满足被100整除的要求
        }
        cnt[pre[i - 1]]++;
    }
    printf("%lld\n", ans);
    return 0;
}