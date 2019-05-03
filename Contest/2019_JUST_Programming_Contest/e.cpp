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

const int maxn = 1e3 + 10;
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int n, p, flag = 1;
        ll ans = 0;
        map<char, int>m;
        char s[maxn], c[maxn], k[maxn];
        scanf("%d%d%s%s%s", &n, &p, s + 1, c + 1, k + 1);
        int lenn = strlen(s + 1);
        rep1(i, 1, lenn)
        {
            if (!m.count(s[i])) m[s[i]] = c[i] - '0';
            else m[s[i]] = min(m[s[i]], c[i] - '0');
        }
        int lenk = strlen(k + 1);
        rep1(i, 1, lenk)
        if (m.count(k[i])) ans += m[k[i]]; else flag = 0;
        if (flag) printf("%lld\n", ans); else puts("-1");
    }
    return 0;
}