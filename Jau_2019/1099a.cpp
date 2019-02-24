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

int w, h, w1, h1, w2, h2;

int main()
{
    cin >> w >> h >> w1 >> h1 >> w2 >> h2;
    for (int i = h; i >= 0; i--)
    {
        w += i;
        if (i == h1)
        {
            w -= w1;
            if (w <= 0) w = 0;
        }
        else if (i == h2)
        {
            w -= w2;
            if (w <= 0) w = 0;
        }
    }
    cout << w << endl;
    return 0;
}