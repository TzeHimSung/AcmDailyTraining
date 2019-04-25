#include <bits/stdc++.h>
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
#define rson (curPos<<1)+1
/* namespace */
using namespace std;
/* header end */

const int maxn = 1e5 + 10;
int x, ans[maxn], p = 0, cnt = 0;

int ch(int k)
{
    k++;
    if (k - (k & -k) == 0) return 1;
    else return 0;
}

int calc(int x)
{
    int ret = 1;
    while (ret <= x) ret <<= 1;
    return ret - 1;
}

int solve(int x)
{
    int ret = 0, cnt = 1;
    while (cnt <= x) cnt <<= 1, ret++;
    return ret;
}

int main()
{
    scanf("%d", &x);
    while (!ch(x))
    {
        p++;
        if (p % 2)
        {
            ans[p] = solve(x);
            x ^= calc(x);
        }
        else x++;
    }
    printf("%d\n", p);
    rep1(i, 1, p) if (i & 1) printf("%d ", ans[i]);
    return 0;
}
