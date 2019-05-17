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

const int maxn = 5e2 + 10;
multiset<ll>s, a;
ll sum = 0;
int n, k;

int main()
{
    s.clear(); a.clear();
    scanf("%d%d", &n, &k);
    rep1(i, 1, n)
    {
        ll x; scanf("%lld", &x);
        for (auto i : a) s.insert(i + x);
        a.insert(x);
    }
    int cnt = 0, total = n * (n - 1) / 2 - k;
    for (auto i : s)
    {
        cnt++; if (cnt <= total) continue;
        sum += i;
    }
    printf("%lld\n", sum);
    return 0;
}