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

const int maxn = 5e5 + 10, lim = 3e5;
int a[maxn], b[maxn], c[maxn], d[maxn];
char s[maxn];

int check(int *c, int sc, int *a, int sa, int *b, int sb) {
    for (int i = 0; i < lim; i++)
        if (c[i] != a[i]) {
            if (c[i] < a[i]) return -1;
            break;
        }
    for (int i = 0; i < lim; i++) d[i] = c[i] - a[i];
    for (int i = lim - 1; i; i--)
        if (d[i] < 0) d[i - 1]--, d[i] += 10;
    int t = 0;
    while (!d[t] && t < lim) t++;
    if (t == lim) return -1;
    for (int i = 0; i < sb; i++)
        if (d[t + i] != b[i]) return -1;
    for (int i = sb; i < lim; i++)
        if (d[t + i]) return -1;
    return lim - sb - t;
}

int main() {
    int casenum; scanf("%d", &casenum);
    while (casenum--) {
        int sa, sb, sc, t;
        rep0(i, 0, maxn) a[i] = b[i] = c[i] = 0;
        scanf("%s", s + 1); sa = strlen(s + 1);
        for (int i = 1; s[i]; i++) a[i] = s[i] - '0';
        scanf("%s", s + 1); sb = strlen(s + 1);
        for (int i = 1; s[i]; i++) b[i] = s[i] - '0';
        scanf("%s", s + 1); sc = strlen(s + 1);
        for (int i = 1; s[i]; i++) c[i] = s[i] - '0';

        // enum four situation
        t = check(c + 1, sc, a + 1, sa, b + 1, sb);
        if (t != -1) {
            printf("%d %d %d", lim - sa, t, lim - sc);
        }
        t = check(c + 1, sc, a, sa + 1, b + 1, sb);
        if (t != -1) {
            printf("%d %d %d", lim - sa - 1, t, lim - sc);
        }
        t = check(c + 1, sc, b + 1, sb, a + 1, sa);
        if (t != -1) {
            printf("%d %d %d", lim - sb, t, lim - sc);
        }
        t = check(c + 1, sc, b, sb + 1, a + 1, sa);
        if (t != -1) {
            printf("%d %d %d", lim - sb - 1, t, lim - sc);
        }
    }
    return 0;
}