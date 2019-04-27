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

const int maxn = 1e4 + 10;
char a[maxn], b[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", a + 1); scanf("%s", b + 1);
        int len1 = strlen(a + 1), len2 = strlen(b + 1);
        int sum1 = 0, sum2 = 0, sign1 = 1, sign2 = 1;
        rep1(i, 1, len1) sum1 += a[i] - '0';
        rep1(i, 1, len2) sum2 += b[i] - '0';
        if (sum1 % 3 == 2) sign1 = 2; if (sum2 % 3 == 1) sign2 = 2;
        printf("%d\n", abs(sign1 - sign2) % 2);
    }
    return 0;
}