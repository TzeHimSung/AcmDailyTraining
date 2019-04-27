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

const int maxn = 2e5 + 10;

int n, s[maxn], cnt[maxn], r[maxn];

int main()
{
    scanf("%d", &n);
    rep1(i, 1, n)
    {
        int x; scanf("%d", &x);
        cnt[x]++;
    }
    for (int i = 2e5; i >= 1; i--)
    {
        if (!cnt[i + 1]) r[i] = i;
        else if (cnt[i + 1] == 1) r[i] = i + 1;
        else r[i] = r[i + 1];
    }
    rep1(i, 1, 2e5) s[i] = s[i - 1] + cnt[i];
    pair<int, int> ans = mp(1, 1);
    rep1(i, 1, 2e5)
    {
        if (!cnt[i]) continue;

    }
    return 0;
}