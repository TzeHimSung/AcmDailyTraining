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

const int maxn = 10;
char s[maxn];

int main()
{
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    int sh = 0, th = 0, day;
    if (len == 3)
    {
        sh = s[1] - '0'; th = 12 + s[2] - '0'; day = s[3] - '0';
    }
    else if (len == 5)
    {
        sh = (s[1] - '0') * 10 + s[2] - '0';
        th = 12 + (s[3] - '0') * 10 + s[4] - '0';
        day = s[5] - '0';
    }
    else
    {
        sh = (s[1] - '0') * 10 + s[2] - '0';
        th = 12 + s[3] - '0';
        day = s[4] - '0';
        if ((sh < 2 || sh > 11) || (th < 14 || th > 23))
        {
            sh = s[1] - '0';
            th = 12 + (s[2] - '0') * 10 + s[3] - '0';
        }
    }
    printf("%d\n", day * (th - sh));
    return 0;
}