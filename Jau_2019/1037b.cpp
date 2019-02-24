/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
/* STL */
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>
#include <iterator>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define fir first
#define sec second
#define init(a,b) fill(begin(a),end(a),b)
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;i++)
#define rep0(i,a,b) for(int i=a;i<b;i++)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_int 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
int n, k, a[maxn], firPos, secPos;
ll ans = 0;

int main()
{
    cin >> n >> k;
    rep0(i, 0, n) cin >> a[i];
    sort(a, a + n);
    firPos = lower_bound(a, a + n, k) - a;
    secPos = upper_bound(a, a + n, k) - a - 1;
    int mid = n / 2 + 1;
    if (firPos + 1 > mid)
    {
        int cnt = firPos + 1 - mid, p = firPos - 1;
        while (cnt--) ans += (ll)(k - a[p--]);
    }
    else if (secPos + 1 < mid)
    {
        int cnt = mid - (secPos + 1), p = secPos + 1;
        while (cnt--) ans += (ll)(a[p++] - k);
    }
    cout << ans << endl;
    return 0;
}