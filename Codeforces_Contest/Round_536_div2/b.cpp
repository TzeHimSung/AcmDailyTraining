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

struct Node
{
    int a, c, pos;
    bool operator<(const Node &rhs)const
    {
        if (c == rhs.c) return pos < rhs.pos;
        else return c < rhs.c;
    }
};
const int maxn = 1e5 + 10;
int n, m, arr[maxn];
Node t[maxn];
ll ans[maxn];

int main()
{
    scanf("%d%d", &n, &m);
    rep1(i, 1, n) scanf("%d", &t[i].a);
    rep1(i, 1, n)
    {
        scanf("%d", &t[i].c); t[i].pos = i;
    }
    sot(t, n);
    rep1(i, 1, n) arr[t[i].pos] = i;
    int j = 1;
    rep1(i, 1, m)
    {
        int xx, yy; scanf("%d%d", &xx, &yy);
        int pos = arr[xx];
        if (t[pos].a >= yy)
        {
            t[pos].a -= yy;
            ans[i] = (ll)t[pos].c * yy;
            yy = 0;
        }
        else
        {
            ans[i] = (ll)t[pos].a * t[pos].c;
            yy -= t[pos].a;
            t[pos].a = 0;
            for (; j <= n; j++)
            {
                if (t[j].a >= yy)
                {
                    t[j].a -= yy;
                    ans[i] += (ll)t[j].c * yy;
                    yy = 0; break;
                }
                else
                {
                    yy -= t[j].a;
                    ans[i] += (ll)t[j].a * t[j].c;
                    t[j].a = 0;
                }

            }
        }
        if (yy)
        {
            ans[i] = 0;
            break;
        }
    }
    rep1(i, 1, m) printf("%lld\n", ans[i]);
    return 0;
}