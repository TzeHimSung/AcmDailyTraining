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
#define inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e3 + 10;
struct Point
{
    int x, y;
};

map<pair<pair<ll, ll>, pair<ll, ll> >, ll>m;
map<pair<ll, ll>, ll>mm;
Point p[maxn];
int n;
ll ans = 0;

int main()
{
    m.clear(); mm.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &p[i].x, &p[i].y);
        for (int j = 1; j < i; j++)
        {
            int xx = p[i].x - p[j].x, yy = p[i].y - p[j].y, zz = xx * p[j].y - yy * p[j].x;
            int gcd = __gcd(xx, yy), gcd2 = __gcd(xx, zz);
            if (!xx)
                m[ {{xx / gcd, yy / gcd}, {p[i].x, inf}}]++;
            else
                m[ {{xx / gcd, yy / gcd}, {xx / gcd2, zz / gcd2}}]++;
        }
    }
    for (auto i : m)
        mm[ {i.fir.fir.fir, i.fir.fir.sec}]++;
    for (auto id : m)
        ans += (int)m.size() - mm[ {id.fir.fir.fir, id.fir.fir.sec}];
    printf("%lld\n", ans / 2);
    return 0;
}