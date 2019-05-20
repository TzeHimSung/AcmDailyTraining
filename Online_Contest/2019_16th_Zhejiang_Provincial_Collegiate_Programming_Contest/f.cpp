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

set<char>ss = { 'a', 'e', 'i', 'y', 'o', 'u' };
const int maxn = 200;
char s[maxn];
int t;

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        printf("%c", s[1]);
        rep1(i, 2, len)
        if (ss.count(s[i])) continue;
        else printf("%c", s[i]);
        puts("");
    }
    return 0;
}