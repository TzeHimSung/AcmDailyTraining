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

struct Node
{
    int x, y, r, q, frac, nume;
};

const int maxn = 1e4 + 10;
Node wheel[maxn];
queue<int>q;
int vis[maxn];

int check(int p, int q)
{
    if ((wheel[p].x - wheel[q].x) * (wheel[p].x - wheel[q].x) + (wheel[p].y - wheel[q].y) * (wheel[p].y - wheel[q].y) == (wheel[p].r + wheel[q].r) * (wheel[p].r + wheel[q].r))
        return 1;
    else return 0;
}

int main()
{
    while (!q.empty()) q.pop();
    int t; scanf("%d", &t);
    while (t--)
    {
        int n; scanf("%d", &n);
        rep1(i, 1, n)
        {
            vis[i] = 0;
            scanf("%d%d%d", &wheel[i].x, &wheel[i].y, &wheel[i].r);
            wheel[i].frac = wheel[i].nume = 1; wheel[i].q = i == 1 ? 1 : 0;
        }
        q.push(1);
        while (!q.empty())
        {
            int curr = q.front(); q.pop();
            if (vis[curr]) continue;
            vis[curr] = 1;
            rep1(i, 1, n)
            {
                if (vis[i]) continue;
                if (check(i, curr))
                {
                    wheel[i].q = -wheel[curr].q;
                    wheel[i].frac = wheel[curr].frac * wheel[curr].r;
                    wheel[i].nume = wheel[curr].nume * wheel[i].r;
                    int gcd = __gcd(wheel[i].frac, wheel[i].nume);
                    wheel[i].frac /= gcd, wheel[i].nume /= gcd;
                    q.push(i);
                }
            }
        }
        rep1(i, 1, n)
        if (!wheel[i].q) puts("not moving");
        else if (wheel[i].q == 1)
        {
            printf("%d", wheel[i].frac);
            if (wheel[i].nume != 1) printf("/%d", wheel[i].nume);
            puts(" clockwise");
        }
        else
        {
            printf("%d", wheel[i].frac);
            if (wheel[i].nume != 1) printf("/%d", wheel[i].nume);
            puts(" counterclockwise");
        }
    }
    return 0;
}