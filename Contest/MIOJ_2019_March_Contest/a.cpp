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

int a, b, c, d, e;
map<int, int>m;

int main()
{
    m.clear();
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
    rep1(i, -50, 50)
    {
        rep1(j, -50, 50)
        {
            rep1(k, -50, 50)
            {
                if (i * j * k == 0) continue;
                m[a * i * i * i + b * j * j * j + c * k * k * k]++;
            }
        }
    }
    int ans = 0;
    rep1(i, -50, 50)
    {
        rep1(j, -50, 50)
        {
            if (i * j == 0) continue;
            ans += m[i * i * i * d + e * j * j * j];
        }
    }
    printf("%d\n", ans);
    return 0;
}