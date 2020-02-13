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

const int maxn = 110;
int t;

int main() {
    scanf("%d", &t);
    while (t--) {
        char a[maxn], b[maxn], c[maxn];
        scanf("%s", a + 1);
        scanf("%s", b + 1);
        scanf("%s", c + 1);
        int len = strlen(a + 1), flag = 1;
        for (int i = 1; i <= len; i++) {
            if (a[i] == c[i] ||  b[i] == c[i] ) continue;
            else {
                flag = 0; break;
            }
        }
        if (flag) puts("YES"); else puts("NO");
    }
    return 0;
}