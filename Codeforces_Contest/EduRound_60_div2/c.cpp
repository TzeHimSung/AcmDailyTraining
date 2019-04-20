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
#define ll_inf 1e17
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

int sx, sy, ex, ey, n, curX = 0, curY = 0;
const int maxn = 1e5 + 10;
char s[maxn];

bool check(ll mid)
{
    ll t = mid / n, re = mid % n, px = sx + t * curX, py = sy + t * curY;
    rep1(i, 1, re)
    {
        if (s[i] == 'U') py++;
        else if (s[i] == 'D') py--;
        else if (s[i] == 'L') px--;
        else if (s[i] == 'R') px++;
    }
    return mid >= abs(px - ex) + abs(py - ey);
}

int main()
{
    // cin >> sx >> sy >> ex >> ey >> n;
    scanf("%d%d%d%d%d", &sx, &sy, &ex, &ey, &n);
    scanf("%s", s + 1);
    rep1(i, 1, n)
    {
        if (s[i] == 'U') curY++;
        else if (s[i] == 'D') curY--;
        else if (s[i] == 'L') curX--;
        else if (s[i] == 'R') curX++;
    }
    ll l = 0, r = ll_inf, ans = -1;
    while (l < r)
    {
        ll mid = (l + r) >> 1;
        if (check(mid))
            ans = r = mid;
        else l = mid + 1;
    }
    // cout << ans << endl;
    printf("%lld\n", ans);
    return 0;
}