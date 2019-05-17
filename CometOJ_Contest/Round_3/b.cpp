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

const int maxn = 1e5 + 10;
int n, ans = 0, start = 0, a[2][maxn];
int pre, flag = 0, lastPos; //pre: 1(up 1 down 0) 2(up 0 down 1) 3(both 1)

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int j = 0; j < n; j++)
    {
        int nowone = 0, nowtwo = 0;
        if (a[0][j] == 1) nowone = 1;
        if (a[1][j] == 1) nowtwo = 1;
        if (nowone || nowtwo)
        {
            if (!flag)
            {
                lastPos = j;
                if (nowone) pre = 1;
                if (nowtwo) pre = 2;
                if (nowone && nowtwo) pre = 3;
                flag = 1;
                continue;
            }
            else
            {
                ans += j - lastPos - 1;
                if (nowone && nowtwo)
                {
                    pre = 3;
                }
                else if (nowone && !nowtwo)
                {
                    if (pre == 2)
                    {
                        ans++;
                        pre = 3;
                    }
                    else pre = 1;
                }
                else if (!nowone && nowtwo)
                {
                    if (pre == 1)
                    {
                        ans++;
                        pre = 3;
                    }
                    else pre = 2;
                }
                lastPos = j;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}