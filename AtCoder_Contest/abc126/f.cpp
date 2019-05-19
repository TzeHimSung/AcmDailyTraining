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

int main()
{
    int n, k;
    cin >> n >> k;
    if (n == 1)
    {
        if (k > 0) printf("-1\n");
        else printf("0 0 1 1\n");
        return 0;
    }
    int all = (1 << n);
    if (k < all)
    {
        if (k == 0)
        {
            for (int i = 0; i < all; i++) printf("%d %d ", i, i);
            return 0;
        }
        for (int i = 1; i < all; i++)
        {
            if (i == k) continue;
            printf("%d ", i);
        }
        printf("%d ", k);
        for (int i = all - 1; i >= 1; i--)
        {
            if (i == k) continue;
            printf("%d ", i);
        }
        printf("0 %d 0\n", k);
        return 0;
    }
    else printf("-1\n");
    return 0;
}