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

const int maxn = 5e2 + 10;
multiset<ll>s, a;
ll sum = 0;
int n, k;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    s.clear(); a.clear();
    scanf("%d%d", &n, &k);
    rep1(i, 1, n)
    {
        ll x; scanf("%lld", &x);
        for (auto i : a) s.insert(i + x);
        a.insert(x);
    }
    int cnt = 0, total = n * (n - 1) / 2 - k;
    for (auto i : s)
    {
        cnt++; if (cnt <= total) continue;
        sum += i;
    }
    printf("%lld\n", sum);
    return 0;
}