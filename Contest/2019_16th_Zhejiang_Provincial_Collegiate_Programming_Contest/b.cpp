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

const int maxn = 1e5 + 10;
ll a[maxn], b[maxn], cnt[maxn];
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        ll n, x, y, curX = 0, curY = 0;
        scanf("%lld%lld%lld", &n, &x, &y);
        rep1(i, 1, n)
        {
            scanf("%lld", &a[i]); b[i - 1] = a[i];
            cnt[i - 1] = 0;
            curX += (i * a[i]); curY += (i * a[i] * a[i]);
        }
        ll deltaX = x - curX, deltaY = y - curY;
        if (!deltaX && deltaY)
        {
            puts("0");
            continue;
        }
        if (!deltaX && !deltaY)
        {
            ll ans = 0;
            sort(b, b + n);
            int m = unique(b, b + n) - b;
            rep1(i, 1, n)
            cnt[lower_bound(b, b + m, a[i]) - b]++;
            rep0(i, 0, m)
            ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
            printf("%lld\n", ans);
            continue;
        }
        if (abs(deltaY) % abs(deltaX))
        {
            puts("0");
            continue;
        }
        ll rough = deltaY / deltaX, ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll fm = rough - 2 * a[i], fs = deltaX / fm, j = i - fs;
            if (!fm) continue;
            if (abs(deltaX) % abs(fm)) continue;
            if (j <= n && j >= 1)
                if (a[i] + a[j] == rough) ans++;
        }
        printf("%lld\n", ans / 2);
    }
    return 0;
}