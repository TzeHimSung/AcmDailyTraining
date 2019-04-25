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

ll a, b, curLcm = 0, ans = 0;

int main()
{
    scanf("%lld%lld", &a, &b);
    curLcm = a * b / __gcd(a, b);
    int delta = abs(a - b);
    for (ll i = 1, tmp; i * i <= delta; i++)
    {
        if (delta % i == 0)
        {
            tmp = i;
            ll p = a / tmp * tmp;
            if (a % tmp) p += tmp;
            ll k = p - a, q = b + k;
            tmp = p / tmp * q;
            if (tmp < curLcm || (tmp == curLcm && k < ans))
            {
                curLcm = tmp;
                ans = k;
            }
            tmp = delta / i;
            p = a / tmp * tmp;
            if (a % tmp) p += tmp;
            k = p - a; q = b + k;
            tmp = p / tmp * q;
            if (tmp < curLcm || (tmp == curLcm && k < ans))
            {
                curLcm = tmp;
                ans = k;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
