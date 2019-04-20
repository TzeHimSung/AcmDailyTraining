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

int n, ans = 1, a = 0, b = 0;

int main()
{
    cin >> n;
    rep1(i, 1, n)
    {
        int x, y; cin >> x >> y;
        if (x == a && y == b) continue; //delete same stat
        if (a > b)
        {
            if (x > y)
            {
                if (y >= a) ans += y - a + 1;
            }
            else ans += x - a + 1;
        }
        else if (a < b)
        {
            if (x < y)
            {
                if (x >= b) ans += x - b + 1;
            }
            else ans += y - b + 1;
        }
        else
            ans += min(x, y) - a;
        a = x, b = y;
    }
    cout << ans << endl;
    return 0;
}