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
int n;
string s[maxn];
ll ans = 0;

int main() {
    scanf("%d", &n);
    rep1(i, 1, n) {
        cin >> s[i];
        sort(s[i].begin(), s[i].end());
    }
    sort(s + 1, s + 1 + n);
    int cnt = 1;
    rep1(i, 2, n) {
        if (s[i] == s[i - 1]) cnt++;
        else {
            ans += (ll)cnt * (cnt - 1) / 2;
            cnt = 1;
        }
    }
    ans += (ll)cnt * (cnt - 1) / 2;
    printf("%lld\n", ans);
    return 0;
}