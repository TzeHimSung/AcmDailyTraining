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

const int maxn = 1e6 + 10;
char s[maxn], t[maxn];
int ls, lt, nxt[maxn];

void kmp_pre()
{
    int i, j;
    i = 0, j = nxt[0] = -1;
    while (i < lt)
    {
        while (-1 != j && t[i] != t[j]) j = nxt[j];
        nxt[++i] = ++j;
    }
}

int kmp()
{
    int i, j, ans; i = j = ans = 0;
    kmp_pre();
    while (i < ls)
    {
        while (-1 != j && s[i] != t[j]) j = nxt[j];
        i++, j++;
        if (j >= lt)
        {
            ans++;
            j = nxt[j];
        }
    }
    return ans;
}

int main()
{
    scanf("%s", s);
    scanf("%s", t);
    ls = strlen(s), lt = strlen(t);
    printf("%d\n", kmp());
    return 0;
}