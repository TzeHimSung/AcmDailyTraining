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

char s[20];
int fu = 0, len, mo = 1, ans = 0;

int main() {
    scanf("%s", s + 1);
    len = strlen(s + 1);
    if (len == 1 && s[1] == '0') return puts("0"), 0;
    if (s[1] == '-') {
        mo = 2;
        fu = 1;
    }
    int i;
    for (i = len; i >= mo; i--)
        if (s[i] != '0') break;
    for (int j = i; j >= mo; j--) ans = ans * 10 + s[j] - '0';
    if (fu) printf("-");
    printf("%d\n", ans);
    return 0;
}