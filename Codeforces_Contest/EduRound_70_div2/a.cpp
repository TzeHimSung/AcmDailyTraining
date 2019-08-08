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
// const int maxn = 10;
int a[maxn], b[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        char p[maxn], q[maxn];
        scanf("%s%s", p + 1, q + 1);
        int len1 = strlen(p + 1), len2 = strlen(q + 1), ans = 0;
        rep1(i, 1, len1) a[i] = p[len1 - i + 1] - '0';
        rep1(i, 1, len2) b[i] = q[len2 - i + 1] - '0';
        rep1(i, 1, len2) {
            if (b[i] == 1) {
                for (int j = i; j <= len1; j++)
                    if (a[j] == 1) {
                        ans = j - i;
                        goto mark;
                    }
            }
        }
mark:
        printf("%d\n", ans);
    }
    return 0;
}