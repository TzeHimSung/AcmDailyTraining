#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll c, n, m, t;
ll p[maxn], txt[maxn];
bool fun(ll cnt, ll d)
{
    ll tt = 0, cnt2 = 0, rest = 0;
    for(int i = 1; i <= n; i++)
    {
        if(p[i] <= d)
        {
            ++cnt2;
            rest += p[i];
            tt += p[i];
            if(cnt2 == cnt && tt <= t) return true;
            if(cnt2 % m == 0)
            {
                tt += rest;
                rest = 0;
            }
            if(tt > t) return false;
        }
    }
    return false;
}
int main()
{
    scanf("%lld", &c);
    while(c--)
    {
        ll minn = 200000000;
        scanf("%lld%lld%lld", &n, &m, &t);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld", &p[i]);
            txt[i] = p[i];
            //  cout<<txt[i]<<endl;
            //minn = min(minn,p[i]);
        }
        sort(txt + 1, txt + 1 + n);
        int l = 1, r = n, mid, ans = 0;
        while(l <= r)
        {
            mid = (l + r) / 2;
            // cout<<mid<<endl<<txt[mid]<<endl;
            //cout<<fun(txt[mid])<<endl;
            if(fun(mid, txt[mid]))
            {
                l = mid + 1;
                ans = mid;
            }
            else
                r = mid - 1;
            // cout<<l<<endl<<r<<endl<<mid<<endl;
        }
        if(ans)
            printf("%d %lld\n", ans, txt[ans]);
        else
            printf("0 1\n");
    }
}