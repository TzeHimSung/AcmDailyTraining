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

const int maxn = 210;
char s[maxn], t[maxn];

int main() {
    scanf("%s", s + 1);
    scanf("%s", t + 1);
    int len1 = strlen(s + 1), len2 = strlen(t + 1), ans = 0;
    if (len1 == len2) return puts("0"), 0;
    for (int k = 1; k <= len1 - len2 + 1; k++) {
        if (s[k] != t[1]) continue;
        int p, q;
        for (p = k, q = 1; p <= len1 && q <= len2;) {
            while (q <= len2 && t[q] != s[p]) p++;
            q++, p++;
        }
        if (q == len2 + 1)
            ans = max({ans, k - 1, len1 - p});
    }
    printf("%d\n", ans);
    return 0;
}