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
int a[maxn];
string s;
ll ans = 0;

int main() {
    cin >> s;
    int len = s.size();
    rep0(i, 0, maxn) a[i] = int_inf;
    rep0(i, 0, len) {
        for (int j = 1; i + 2 * j < len; j++)
            if (s[i] == s[i + j] && s[i] == s[i + 2 * j]) {
                a[i] = i + 2 * j;
                break;
            }
    }
    for (int i = len - 1; i >= 0; i--) a[i] = min(a[i], a[i + 1]);
    rep0(i, 0, len)
    if (a[i] != int_inf) ans += len - a[i];
    printf("%lld\n", ans);
    return 0;
}