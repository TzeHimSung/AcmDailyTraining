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

string s, t;

int main() {
    cin >> s >> t;
    int len1 = s.size(), len2 = t.size();
    vector<int>pre(len2), suf(len2);
    int cur = 0;
    for (int i = 0; cur < len2; i++)
        if (s[i] == t[cur])
            pre[cur++] = i;
    cur = len2;
    for (int i = len1; i--;) {
        if (s[i] == t[cur - 1])
            suf[--cur] = i;
    }
    int ans = max(len1 - 1 - pre.back(), suf[0]);
    for (int i = 0; i + 1 < len2; i++)
        ans = max(ans, suf[i + 1] - pre[i] - 1);
    printf("%d\n", ans);
    return 0;
}