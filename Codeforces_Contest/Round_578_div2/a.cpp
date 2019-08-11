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
int n, a[20];
char s[maxn];

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'L') {
            for (int i = 0; i < 10; i++)
                if (!a[i]) {
                    a[i] = 1; break;
                }
        } else if (s[i] == 'R') {
            for (int i = 9; i >= 0; i--)
                if (!a[i]) {
                    a[i] = 1; break;
                }
        } else a[s[i] - '0'] = 0;
    }
    for (int i = 0; i < 10; i++) printf("%d", a[i]);
    puts("");
    return 0;
}