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
const int dpmaxn = 256;
vector<int>dat[26];
char s[maxn], t[3][1e3 + 10];
int cnt[3], n, Q, dp[dpmaxn][dpmaxn][dpmaxn];

void add(int )

int main()
{
    scanf("%d%d", &n, &Q);
    scanf("%s", s + 1);
    rep1(i, 1, n)
    dat[s[i] - 'a'].pb(i);
    while (Q--)
    {
        char op[3], ch; int a;
        scanf("%s", op);
        if (op[0] == '+')
        {
            scanf("%d %c", &a, &ch);
            add(a - 1, ch);
        }
        else
        {
            scanf("%d", &a);
            del(a - 1);
        }
        if (dp[cnt[0]][cnt[1]][cnt[2]] <= n) puts("YES");
        else puts("NO");
    }
    return 0;
}