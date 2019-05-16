/* basic header */
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
#define rson curPos<<1|1
/* namespace */
using namespace std;
/* header end */

const int maxn = 6;
int a[maxn] = {4, 8, 15, 16, 23, 42}, b[6];

int main()
{
    rep0(i, 0, 4)
    {
        printf("? %d %d\n", i + 1, i + 2); fflush(stdout);
        scanf("%d", &b[i]);
    }
    do
    {
        if (a[0]*a[1] == b[0] && a[1]*a[2] == b[1] && a[2]*a[3] == b[2] && a[3]*a[4] == b[3])
            return printf("! %d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5]), 0;
    } while (next_permutation(a, a + 6));
    return 0;
}