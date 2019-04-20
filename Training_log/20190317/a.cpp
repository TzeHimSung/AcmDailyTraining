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

int t, a, b, c, d, cnt;

int main()
{
    while (cin >> t)
    {
        while (t--)
        {
            cnt = 0;
            cin >> a >> b >> c >> d;
            if (a) cnt++;
            if (b) cnt++;
            if (c) cnt++;
            if (d) cnt++;
            if (!cnt) puts("Typically Otaku");
            else if (cnt == 1) puts("Eye-opener");
            else if (cnt == 2) puts("Young Traveller");
            else if (cnt == 3) puts("Excellent Traveller");
            else puts("Contemporary Xu Xiake");
        }
    }
    return 0;
}