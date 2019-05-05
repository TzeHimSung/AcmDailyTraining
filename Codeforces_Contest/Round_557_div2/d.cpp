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

const int maxn = 1e5 + 10;
vector<int> a[maxn];
int n, m;

int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y; scanf("%d%d", &x, &y); x--; y--;
        if (x > y) swap(x, y);
        if (abs(x - y) > n / 2) swap(x, y);
        a[x].pb(min(abs(x - y), n - abs(x - y)));
        if (abs(x - y) == n / 2) a[y].pb(n / 2);
    }
    rep0(i, 0, n) sort(a[i].begin(), a[i].end());
    rep1(i, 1, n / 2)
    if (!(n % i))
    {
        for (int j = i; j < n; j += i)
            for (int k = j; k < j + i; k++)
                if (a[k] != a[k - i]) goto mark;
        return puts("Yes"), 0;
        mark:;
    }
    puts("No");
    return 0;
}
