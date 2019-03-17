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

const double pi = acos(-1.0);
double a, b, r, d;
int t;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> r >> d;
        double k = sqrt(b * b + (a + r) * (a + r)), dToH = d * pi / 180.0, kk = acos((a + r) / k);
        if (dToH > kk)
            printf("%.12f\n", k - r);
        else
        {
            double l = 2 * k * sin((kk - dToH) / 2), p = l * cos((pi - kk + dToH) / 2);
            printf("%.12f\n", k - p - r);
        }
    }
    return 0;
}