#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n, k, last = 0, ans = 0;
    bool a = false;
    scanf("%I64d%I64d", &n, &k);
    for(ll i = 0; i < n; i++)
    {
        ll tmp;
        scanf("%I64d", &tmp);
        if(last && a)
        {
            if(last + tmp < k)
            {
                last = 0;
                ans++;
                continue;
            }
        }
        a = true;
        last += tmp;
        // cout<<last<<endl;
        ans += (last / k);
        last = last % k;
    }
    if(last) ans++;
    printf("%I64d\n", ans);
    return 0;
}