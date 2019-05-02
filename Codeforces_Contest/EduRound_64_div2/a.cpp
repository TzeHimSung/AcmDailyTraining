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
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curPos<<1
#define rson (curPos<<1)+1
/* namespace */
using namespace std;
/* header end */

int n, last = 0, ans = 0, flag = 1, llast = 0;

int main()
{
    scanf("%d%d", &n, &last);
    n--;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        if (last == 1)
        {
            if (x == 1)
            {
                flag = 0;
            }
            else if (x == 2)
            {
                if (llast + last == 4)
                    ans += 2;
                else
                    ans += 3;
            }
            else if (x == 3)
                ans += 4;
        }
        else if (last == 2)
        {
            if (x == 2)
            {
                ans += 3;
            }
            else if (x == 1)
                ans += 3;
            else if (x == 3)
            {
                flag = 0;
            }
        }
        else if (last == 3)
        {
            if (x == 3)
            {
                ans += 4;
            }
            else if (x == 1)
                ans += 4;
            else if (x == 2)
            {
                flag = 0;
            }
        }
        if (i >= 1)
            llast = last;
        last = x;
    }
    if (!flag)
        puts("Infinite");
    else
    {
        puts("Finite");
        printf("%d\n", ans);
    }
    return 0;
}
