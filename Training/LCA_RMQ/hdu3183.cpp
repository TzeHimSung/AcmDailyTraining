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

const int maxn = 1e3 + 10;
char s[maxn], ans[maxn];
int n;

int main()
{
    while (scanf("%s%d", s, &n) != EOF)
    {
        int l = 0, r = n, k = 0;
        n = strlen(s) - n;
        while (n--)
        {
            int pos = l;
            rep1(i, l, r)
            if (s[pos] > s[i]) pos = i;
            ans[k++] = s[pos];
            l = pos + 1, r++;
        }
        int head = 0;
        while (ans[head] == '0' && head < k) head++;
        if (head == k) puts("0");
        else
        {
            for (; head < k; head++) printf("%c", ans[head]);
            puts("");
        }
    }
    return 0;
}