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
int n, a[maxn], cnt[maxn], b[maxn], used, ans = 1;

int main()
{
    scanf("%d", &n);
    rep1(i, 1, n) scanf("%d", &a[i]);
    rep1(i, 1, n)
    {
        if (!cnt[a[i]]) used++;
        b[cnt[a[i]]]--; cnt[a[i]]++; b[cnt[a[i]]]++;
        if (b[cnt[a[i]]] == used - 1 && b[cnt[a[i]] + 1] == 1) ans = i;
        if (b[cnt[a[i]]] == used - 1 && b[1] == 1) ans = i;
        if (b[cnt[a[i]]] == 1 && b[cnt[a[i]] - 1] == used - 1) ans = i;
        if (b[cnt[a[i]]] == used && i != n) ans = i + 1;
    }
    printf("%d\n", ans);
    return 0;
}