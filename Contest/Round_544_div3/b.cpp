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

const int maxn = 1e2 + 10;
// const int maxn = 10;
int n, k, a[maxn], ans = 0;

int main()
{
    rep0(i, 0, maxn) a[i] = 0;
    cin >> n >> k;
    rep1(i, 1, n)
    {
        int x; cin >> x;
        a[x % k]++;
    }
    if (a[0] & 1) ans += a[0] - 1; else ans += a[0];
    rep1(i, 1, k / 2)
    {
        if (i == k / 2 && k % 2 == 0)
        {
            if (a[i] & 1) ans += a[i] - 1;
            else ans += a[i];
        }
        else ans += min(a[i], a[k - i]) * 2;
    }
    cout << ans << endl;
    return 0;
}