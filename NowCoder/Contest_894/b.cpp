#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define sot(a,b) sort(a+1,a+1+b)
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define eps 1e-8
#define int_inf (1<<30)-1
#define ll_inf (1LL<<62)-1
#define lson curPos<<1
#define rson curPos<<1|1

using namespace std;

const int maxn = 1e3 + 10;
int n, m;
ll l, r, a[maxn], b[maxn], c[maxn * maxn], ans = 0; //a b是a b数组前缀和

int main()
{
    scanf("%d%d%lld%lld", &n, &m, &l, &r);
    for (int i = 1; i <= n; i++)
    {
        ll x; scanf("%lld", &x);
        a[i] = a[i - 1] + x;
    }
    for (int i = 1; i <= m; i++)
    {
        ll x; scanf("%lld", &x);
        b[i] = b[i - 1] + x;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) //不同区间的b数组之和
    {
        for (int j = i + 1; j <= m; j++)
            c[++cnt] = b[j] - b[i];
    }
    sort(c + 1, c + 1 + cnt);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++) //枚举a数组区间
        {
            ll x = a[j] - a[i], u = (l - 1) / x + 1, v = r / x;
            ll lab1 = lower_bound(c + 1, c + 1 + cnt, u) - c;
            ll lab2 = upper_bound(c + 1, c + 1 + cnt, v) - c;
            ans += lab2 - lab1;
        }
    printf("%lld\n", ans);
    return 0;
}