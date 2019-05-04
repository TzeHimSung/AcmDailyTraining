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
char s[maxn][1];
int a[maxn], n;

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        ll numW = 0, numB = 0;
        rep0(i, 0, n)
        {
            scanf("%d%s", &a[i], s[i]);
            if (s[i][0] == 'W') numW += a[i];
            else numB += a[i];
        }
        if (!numW) printf("%lld\n", numB);
        else if (!numB) printf("%lld\n", numW);
        else
        {
            int ans = 0; ll gcd = __gcd(numW, numB), lastW = 0, lastB = 0;
            numW /= gcd, numB /= gcd;
            rep0(i, 0, n)
            if (s[i][0] == 'W')
            {
                if (!(lastB % numB))
                {
                    if ((lastW + a[i]) / numW >= lastB / numB && lastW / numW < lastB / numB) ans++;
                }
                lastW += a[i];
            }
            else
            {
                if (!(lastW % numW))
                {
                    if ((lastB + a[i]) / numB >= lastW / numW && lastB / numB < lastW / numW) ans++;
                }
                lastB += a[i];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}