/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <climits>
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
#define int int32_t
#define ll int64_t
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
#define inf 0x3f3f3f3f
#define lson curr<<1
#define rson curr<<1|1
/* namespace */
using namespace std;
/* header end */

ll t, n, a, b, k;

int main()
{
    cin >> t >> n >> a >> b >> k;
    ll l = 0, r = t;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2, x = min(a, mid), y = min(b, mid), p, q;
        if (n & 1) p = n / 2 + 1, q = n / 2;
        else p = q = n / 2;
        if ((x * p + y * q) < k * mid) r = mid - 1;
        else l = mid;
    }
    cout << l << endl;
    return 0;
}