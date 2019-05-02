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
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curPos<<1
#define rson (curPos<<1)+1
/* namespace */
using namespace std;
/* header end */

const int maxn = 2e5 + 10;
int a[maxn], n;

ll solve(int l, int r)
{
    if (r - l == 1) return 0;
    int mid = l + r >> 1;
    ll ret = solve(l, mid) + solve(mid, r); //避免处理长度为1的区间
    {
        set<int>s;
        //把p当做区间的左端点&&最大值，往右扩展。下法同理。
        for (int i = mid - 1, j = mid, p = 0; i >= l; i--)
        {
            p = max(p, a[i]);
            while (j < r && a[j] < p) s.insert(a[j++]);
            ret += s.count(p - a[i]);
        }
    }
    {
        set<int>s;
        for (int i = mid, j = mid - 1, p = 0; i < r; i++)
        {
            p = max(p, a[i]);
            while (j >= l && a[j] < p) s.insert(a[j--]);
            ret += s.count(p - a[i]);
        }
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    rep0(i, 0, n) scanf("%d", &a[i]);
    printf("%lld\n", solve(0, n));
    return 0;
}