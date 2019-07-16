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
#define mid (curl+curr>>1)
/* namespace */
using namespace std;
/* header end */

ll x, y, z;

int main() {
    cin >> x >> y >> z;
    cout << (x + y) / z << " ";
    ll a = (x + y) % z, b = y / z, c = x / z;
    if (x % z + y % z == a) return puts("0"), 0; // the most balanced state
    if (x % z) c++; if (y % z) b++;
    cout << min(b * z - y, c * z - x) << endl;
    return 0;
}