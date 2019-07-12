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
#define lson curpos<<1
#define rson curpos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
char s[maxn];
int len;

int main() {
    scanf("%s", s + 1);
    len = strlen(s + 1);
    int a = 0, b = 0, c = 0;
    rep1(i, 1, len) {
        if (s[i] == '1') a++;
        else if (s[i] == '4') b++;
        else if (s[i] == '5') c++;
    }
    a /= 3; b /= 2;
    printf("%d\n", min(a, min(b, c)));
    return 0;
}