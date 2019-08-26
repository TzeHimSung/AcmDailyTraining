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

const int maxn = 1010;
int n, a[maxn][maxn];

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) a[i][j] = cnt++;
    for (int i = 0; i < n / 4; i++)
        for (int j = 0; j < n / 4; j++)
            if (i || j) {
                for (int p = 0; p < 4; p++)
                    for (int q = 0; q < 4; q++)
                        a[i * 4 + p][j * 4 + q] = cnt++;
            }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}
