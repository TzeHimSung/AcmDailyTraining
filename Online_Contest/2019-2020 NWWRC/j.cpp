/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(ans,b) sort(ans+1,ans+1+b)
#define rep1(i,ans,b) for(int i=ans;i<=b;++i)
#define rep0(i,ans,b) for(int i=ans;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson (curpos<<1)
#define rson (curpos<<1|1)
/* namespace */
using namespace std;
/* header end */

const int maxn = 510;
int n, a[maxn][maxn], ans[maxn][maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%1d", &a[i][j]);
    for (int i = n - 1; i >= 1; i--)
        for (int j = i; j <= n; j++) {
            int contribute = 0;
            for (int k = i + 1; k < j; k++) contribute = (contribute + ans[i][k] * a[k][j]) % 10;
            if (contribute != a[i][j]) ans[i][j] = 1;
        }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%d", ans[i][j]);
        puts("");
    }
    return 0;
}