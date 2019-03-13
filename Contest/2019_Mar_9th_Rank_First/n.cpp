/* basic header */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdint>
#include <climits>
#include <float.h>
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
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        int a[maxn], l[maxn], r[maxn];
        cin >> n;
        rep1(i, 1, n) cin >> a[i];
        l[1] = a[1], r[n] = a[n];
        rep1(i, 2, n) l[i] = __gcd(l[i - 1], a[i]);
        for (int i = n - 1; i >= 1; i--) r[i] = __gcd(r[i + 1], a[i]);
        int ans = max(l[n - 1], r[2]);
        for (int i = 2; i < n; i++) ans = max(ans, __gcd(l[i - 1], r[i + 1]));
        cout << ans << endl;
    }
    return 0;
}