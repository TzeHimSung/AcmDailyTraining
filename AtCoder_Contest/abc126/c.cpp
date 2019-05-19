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

int n, k;
double ans = 0;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        if (i >= k) ans += 1.0 / n;
        else
        {
            int tmp = i, cnt = 0;
            while (tmp < k) tmp *= 2, cnt++;
            ans += 1.0 / n * pow(0.5, (double)cnt);
        }
    }
    printf("%.9f\n", ans);
    return 0;
}