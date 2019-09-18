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
int n, vis[maxn];
char s[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int solved = 0;
        scanf("%d", &n);
        scanf("%s", s + 1);
        for (int p = 0; p <= 9; p++) { // enum each number as start number and end number
            int cnt = 0, pre = p, noSolution = 0;
            for (int i = 1; i <= n; i++) vis[i] = 0; // vis sign
            for (int i = n; i >= 1; i--) // enum each position in decrease order
                if (s[i] - '0' <= pre) cnt++, vis[i] = 1, pre = s[i] - '0'; // cnt is num of colored number
                else if (s[i] - '0' < p) { // s[i] - '0' > pre, check if s[i] - '0' less then start number
                    noSolution = 1;
                    break;
                }
            if (noSolution) continue;
            pre = p; // pre as start number
            for (int i = 1; i <= n; i++) // in increasing order
                if (s[i] - '0' >= pre && !vis[i]) cnt++, vis[i] = 2, pre = s[i] - '0';
                else if (s[i] - '0' > p) { // p as end number
                    noSolution = 1;
                    break;
                }
            if (noSolution || cnt != n) continue;
            for (int i = 1; i <= n; i++) printf("%d", vis[i]);
            puts("");
            solved = 1;
            break;
        }
        if (!solved) puts("-");
    }
    return 0;
}
