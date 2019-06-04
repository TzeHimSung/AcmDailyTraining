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

int n, last, x;

int main() {
    cin >> n >> x;
    n = 1 << n;
    cout << (x < n ? n / 2 : n) - 1 << endl;
    rep0(i, 1, n)
    if (i < (i ^ x)) {
        cout << (i ^ last) << " ";
        last = i;
    }
    puts("");
    return 0;
}