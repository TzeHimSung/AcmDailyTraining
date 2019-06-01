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

const int maxn = 20;
int a[maxn];

int main() {
    rep0(i, 0, maxn) a[i] = 0;
    rep1(i, 1, 18) {
        int x; cin >> x;
        a[x]++;
    }
    rep0(i, 1, maxn) {
        if (a[i] == 2 || a[i] == 4) a[i] = 0;
        if (a[i] == 3) a[i] -= 2;
    }
    int ans = 0;
    rep0(i, 0, maxn) ans += a[i];
    cout << ans << endl;
    return 0;
}