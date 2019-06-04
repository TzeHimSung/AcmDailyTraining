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
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e3 + 10;
int n, m, q, a[maxn][maxn], curr = 0;

int main() {
    cin >> n >> m >> q;
    rep0(i, 1, n) {
        rep0(j, 1, m) {
            a[i][j] = 1;
            curr++;
        }
    }
    cout << curr << endl;
    while (q--) {
        int x, y; cin >> x >> y;
        rep0(i, 0, 2) {
            rep0(j, 0, 2) {
                if (a[x - i][y - j]) a[x - i][y - j] = 0, curr--;
            }
        }
        printf("%d\n", curr);
    }
    return 0;
}