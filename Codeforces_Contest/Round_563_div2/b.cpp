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

const int maxn = 1e5 + 10;
int n, a[maxn], f1 = 0, f2 = 0;

int main() {
    cin >> n;
    rep1(i, 1, n) {
        cin >> a[i];
        if (a[i] & 1) f1 = 1; else f2 = 1;
    }
    if (f1 && f2) sot(a, n);
    rep1(i, 1, n) cout << a[i] << " ";
    puts("");
    return 0;
}