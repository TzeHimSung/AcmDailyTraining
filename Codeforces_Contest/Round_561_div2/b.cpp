/* basic header */
#include <bits/stdc++.h>
/* define */
#define ll long long
#define dou double
#define pb emplace_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep1(i,a,b) for(int i=a;i<=b;++i)
#define rep0(i,a,b) for(int i=a;i<b;++i)
#define eps 1e-8
#define int_inf 0x3f3f3f3f
#define ll_inf 0x7f7f7f7f7f7f7f7f
#define lson curPos<<1
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

int k, n, m, flag = 0;
string s = "aeiou";

int main()
{
    scanf("%d", &k);
    rep1(i, 1, k)
    if (k % i == 0 && i >= 5 && k / i >= 5)
    {
        n = i, m = k / i, flag = 1; break;
    }
    if (!flag) return puts("-1"), 0;
    rep0(i, 0, n) rep0(j, 0, m) printf("%c", s[(i + j) % 5]);
    puts("");
    return 0;
}