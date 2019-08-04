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

const int maxn = 1e3 + 10;
int v[maxn], puted[maxn];

int main() {
    int t; scanf("%d", &t);
    for (int caseNum = 1; caseNum <= t; caseNum++) {
        int n, k, sum = 0; scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &v[i]); sum += v[i];
        }
        sot(v, n);
        int limV = max(v[n], sum / k);
        for (int curV = limV;; curV++) {
            for (int i = 1; i <= n; i++) puted[i] = 0;
            int cnt = 0;
            for (int i = 1; i <= k; i++) {
                int tmpV = curV;
                for (int j = n; j > 0; j--) {
                    if (!puted[j] && v[j] <= tmpV) {
                        puted[j] = 1;
                        tmpV -= v[j];
                        cnt++;
                    }
                }
            } if (cnt == n) {
                printf("Case #%d: %d\n", caseNum, curV);
                break;
            }
        }
    }
}
