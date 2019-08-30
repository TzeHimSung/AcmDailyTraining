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

const int maxn = 3e5 + 10;
int n, pos[3] = {0, 1, 2};
char s[4], t[4], ans[maxn];

int check() {
    for (int i = 1; i < 3 * n; i++) {
        if (ans[i - 1] == s[0] && ans[i] == s[1]) return 0;
        if (ans[i - 1] == t[0] && ans[i] == t[1]) return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);
    puts("YES");
    do {
        int res = 0;
        for (int k = 0; k < 3; k++)
            for (int i = 0; i < n; i++)
                ans[res++] = 'a' + pos[k];
        if (check()) {
            printf("%s\n", ans);
            return 0;
        }
    } while (next_permutation(pos, pos + 3));
    do {
        int res = 0;
        for (int i = 0; i < n; i++)
            for (int k = 0; k < 3; k++)
                ans[res++] = 'a' + pos[k];
        if (check()) {
            printf("%s\n", ans);
            return 0;
        }
    } while (next_permutation(pos, pos + 3));
    return 0;
}

