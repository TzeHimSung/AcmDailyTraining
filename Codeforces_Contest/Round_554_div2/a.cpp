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

const int maxn = 1e5;
int n, m, ja = 0, oa = 0, jb = 0, ob = 0;

int main()
{
    scanf("%d%d", &n, &m);
    rep1(i, 1, n)
    {
        int x; scanf("%d", &x);
        if (x & 1) ja++; else oa++;
    }
    rep1(i, 1, m)
    {
        int x; scanf("%d", &x);
        if (x & 1) jb++; else ob++;
    }
    int ans = 0;
    ans = min(ja, ob); ans += min(oa, jb);
    printf("%d\n", ans);
    return 0;
}
