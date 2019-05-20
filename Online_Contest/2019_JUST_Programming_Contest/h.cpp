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
        char s[maxn]; scanf("%s", s + 1);
        int len = strlen(s + 1), flag = 1;
        rep0(i, 1, len)
        {
            if (s[i] != 'z' && s[i + 1] - s[i] != 1) flag = 0;
            else if (s[i] == 'z' && s[i + 1] != 'a') flag = 0;
        }
        if (flag) puts("YES"); else puts("NO");
    }
    return 0;
}