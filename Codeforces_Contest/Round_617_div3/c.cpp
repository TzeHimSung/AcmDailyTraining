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

const int maxn = 2e5 + 10;
char s[maxn];
int n, t;
map<pair<int, int>, int>m;

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        int ans = n + 1, l, r, x = 0, y = 0;
        m.clear(); m[mp(0, 0)] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'L') x--;
            if (s[i] == 'R') x++;
            if (s[i] == 'U') y++;
            if (s[i] == 'D') y--;
            int v = m[mp(x, y)];
            if (v) {
                if (ans > i - v + 1) {
                    ans = i - v + 1;
                    l = v, r = i;
                }
            }
            m[mp(x, y)] = i + 1;
        }
        if (ans == n + 1) puts("-1");
        else printf("%d %d\n", l, r);
    }
    return 0;
}