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

const int maxn = 10;
int a[maxn], cnt = 0;

int main() {
    while (cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5]) {
        sort(a + 1, a + 6);
        cout << "Case " << ++cnt << ": " << a[1];
        for (int i = 2; i < 6; i++) cout << " " << a[i];
        cout << endl;
    }
    return 0;
}