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
#define ll_int 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e2 + 10;
int a[maxn], n, m, ans = 0;

int calc(int x)
{
    int tot = 0;
    for (int i = n; i > 0; i--)
    {
        tot += a[i] - ((n - i) / x);
        if (tot >= m) return 1;
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    rep1(i, 1, n) cin >> a[i];
    sot(a, n);
    int l = 1, r = n + 2;
    while (l < r)
    {
        if (l + 1 == r)
        {
            if (!l)
            {
                ans = 1;
                break;
            }
            if (calc(l)) ans = l;
            else if (calc(r)) ans = r;
            else ans = -1;
            break;
        }
        int mid = l + (r - l) / 2;
        if (calc(mid)) r = mid;
        else l = mid;
    }
    cout << ans << endl;
    return 0;
}