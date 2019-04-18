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
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define repa(i,a) for(auto &i:a)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

int a, b, c, ans = 0;

int main()
{
    scanf("%d%d%d", &a, &b, &c);
    int week = min(a / 3, min(b / 2, c / 2));
    a -= week * 3, b -= week * 2, c -= week * 2, ans += week * 7;
    int pre = ans;
    rep1(i, 1, 7)
    {
        int x = a, y = b, z = c, tmp = pre;
        rep1(j, i, i + 6)
        {
            int curr = j > 7 ? j - 7 : j;
            if (curr == 1 || curr == 4 || curr == 7)
            {
                if (x)x--, tmp++; else break;
            }
            else if (curr == 2 || curr == 6)
            {
                if (y) y--, tmp++; else break;
            }
            else if (curr == 3 || curr == 5)
            {
                if (z) z--, tmp++; else break;
            }
        }
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}